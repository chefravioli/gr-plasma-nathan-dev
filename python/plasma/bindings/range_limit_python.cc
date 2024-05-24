/*
 * Copyright 2024 Free Software Foundation, Inc.
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
/* BINDTOOL_HEADER_FILE(range_limit.h)                                        */
/* BINDTOOL_HEADER_FILE_HASH(0d827619d02e57988006cb1f81e2c996)                     */
/***********************************************************************************/

#include <pybind11/complex.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

namespace py = pybind11;

#include <gnuradio/plasma/range_limit.h>
// pydoc.h is automatically generated in the build directory
#include <range_limit_pydoc.h>

void bind_range_limit(py::module& m)
{

    using range_limit    = ::gr::plasma::range_limit;


    py::class_<range_limit, gr::block, gr::basic_block,
        std::shared_ptr<range_limit>>(m, "range_limit", D(range_limit))

        .def(py::init(&range_limit::make),
           py::arg("min_range") = 100,
           py::arg("max_range") = 10000,
           py::arg("abs_max_range") = false,
           py::arg("multiplier") = 1,
           D(range_limit,make)
        )
        



        ;




}








