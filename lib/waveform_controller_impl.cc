/* -*- c++ -*- */
/*
 * Copyright 2022 gr-plasma author.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#include "waveform_controller_impl.h"
#include <gnuradio/io_signature.h>
#include <gnuradio/pdu.h>

namespace gr {
namespace plasma {

using output_type = gr_complex;
waveform_controller::sptr waveform_controller::make(double prf, double samp_rate)
{
    return gnuradio::make_block_sptr<waveform_controller_impl>(prf, samp_rate);
}


/*
 * The private constructor
 */
waveform_controller_impl::waveform_controller_impl(double prf, double samp_rate)
    : gr::block("waveform_controller",
                gr::io_signature::make(0, 0, 0),
                gr::io_signature::make(0, 0, 0))
{
    message_port_register_in(pmt::mp("in"));
    message_port_register_out(pmt::mp("out"));
    set_msg_handler(pmt::mp("in"),
                    [this](const pmt::pmt_t& msg) { handle_message(msg); });
    d_sample_index = 0;
    d_updated = false;
    d_prf = prf;
    d_samp_rate = samp_rate;
    d_num_samp_pri = round(samp_rate / prf);
}

/*
 * Our virtual destructor.
 */
waveform_controller_impl::~waveform_controller_impl() {}

void waveform_controller_impl::handle_message(const pmt::pmt_t& msg)
{
    if (pmt::is_pdu(msg)) {
#pragma message("Remove this debug repeating for loop")
        pmt::pmt_t meta = pmt::car(msg);
        pmt::pmt_t data = pmt::cdr(msg);
        d_num_samp_waveform = pmt::length(data);
        // Zero pad to the length of the PRI
        d_data = c32vector_elements(data);
        d_data.insert(d_data.end(), d_num_samp_pri - d_num_samp_waveform, 0);
        // Send the new waveform through the message port (with additional
        // metadata)
        meta = pmt::dict_add(meta, pmt::intern("prf"), pmt::from_double(d_prf));
        meta = pmt::dict_add(
            meta, pmt::intern("sample_start"), pmt::from_long(d_sample_index));
        message_port_pub(
            pmt::mp("out"),
            pmt::cons(meta, pmt::init_c32vector(d_data.size(), d_data.data())));
        d_sample_index += d_num_samp_pri;

    } else if (pmt::is_pair(msg)) {
        pmt::pmt_t key = pmt::car(msg);
        pmt::pmt_t val = pmt::cdr(msg);
        if (pmt::eq(key, pmt::mp("prf"))) {
            double new_prf = pmt::to_double(val);
            if (round(d_samp_rate / new_prf) > d_num_samp_waveform) {
                d_prf = new_prf;
                d_num_samp_pri = round(d_samp_rate / d_prf);
                d_updated = true;
            } else {
                GR_LOG_ERROR(d_logger, "PRI is less than the waveform duration");
            }
        }
    }
}

} /* namespace plasma */
} /* namespace gr */
