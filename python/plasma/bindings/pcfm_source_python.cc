/*
 * Copyright 2022 Free Software Foundation, Inc.
 *
 * This file is part of GNU Radio
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 */

/***********************************************************************************/
/* This file is automatically generated using bindtool and can be manually edited  */
/* The following lines can be configured to regenerate this file during cmake      */
/* If manual edits are made, the following tags should be modified accordingly.    */
/* BINDTOOL_GEN_AUTOMATIC(0)                                                       */
/* BINDTOOL_USE_PYGCCXML(0)                                                        */
/* BINDTOOL_HEADER_FILE(pcfm_source.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(c5e9c666cc3514405a1511c3bf93eede)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/plasma/pcfm_source.h>
// pydoc.h is automatically generated in the build directory
#include <pcfm_source_pydoc.h>

void bind_pcfm_source(py::module& m)
{

    using pcfm_source = ::gr::plasma::pcfm_source;


    py::class_<pcfm_source, gr::block, gr::basic_block, std::shared_ptr<pcfm_source>>(
        m, "pcfm_source", D(pcfm_source))

        .def(py::init(&pcfm_source::make),
             py::arg("code"),
             py::arg("n"),
             py::arg("over"),
             py::arg("samp_rate"),
             D(pcfm_source, make))


        .def("set_metadata_keys",
             &pcfm_source::set_metadata_keys,
             py::arg("label_key"),
             py::arg("phase_code_class_key"),
             py::arg("n_phase_code_chips_key"),
             py::arg("duration_key"),
             py::arg("sample_rate_key"),
             D(pcfm_source, set_metadata_keys))

        ;
}
