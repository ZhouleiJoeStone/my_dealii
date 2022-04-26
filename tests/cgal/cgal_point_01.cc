// ---------------------------------------------------------------------
//
// Copyright (C) 2020 by the deal.II authors
//
// This file is part of the deal.II library.
//
// The deal.II library is free software; you can use it, redistribute
// it, and/or modify it under the terms of the GNU Lesser General
// Public License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
// The full text of the license can be found in the file LICENSE.md at
// the top level directory of deal.II.
//
// ---------------------------------------------------------------------

// Test conversion from CGAL to deal.II Point and viceversa

#include <deal.II/base/point.h>

#include <CGAL/IO/io.h>
#include <CGAL/Simple_cartesian.h>
#include <deal.II/cgal/utilities.h>

#include "../tests.h"

using namespace CGALWrappers;

int
main()
{
  initlog();
  using CGALPoint = CGAL::Point_3<CGAL::Simple_cartesian<double>>;
  // Test conversion from deal.II Point to CGAL Point
  {
    const Point<3> p(1.0, 2.0, 3.0);
    const auto     cgal_point = to_cgal<CGALPoint>(p);
    deallog << "CGAL Point: " << cgal_point << std::endl;
  }

  // Test conversion from CGAL Point to deal.II Point
  {
    const CGALPoint cgal_point(1.0, 2.0, 3.0);
    const auto      deal_ii_point = to_dealii<3>(cgal_point);
    deallog << "deal.II Point: " << deal_ii_point << std::endl;
  }
}
