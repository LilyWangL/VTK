/*=========================================================================

  Program:   Visualization Toolkit
  Module:    TestPolyhedron1.cxx

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

#include "vtkUnstructuredGrid.h"
#include "vtkPolyhedron.h"
#include "vtkPlane.h"

#include "vtkTestUtilities.h"
#include "vtkNew.h"
#include "vtkCutter.h"
#include "vtkPlane.h"
#include "vtkXMLUnstructuredGridReader.h"

// Test of contour/clip of vtkPolyhedron. uses input from http://www.vtk.org/Bug/view.php?id=14485
int TestPolyhedron2( int argc, char* argv[] )
{
  if (argc < 3) return 1; // test not run with data on the command line
  const char* filename = argv[2];
  vtkNew<vtkXMLUnstructuredGridReader> reader;
  reader->SetFileName(filename);
  reader->Update();

  vtkUnstructuredGrid* pGrid = reader->GetOutput();

  vtkNew<vtkCutter> cutter;
  vtkNew<vtkPlane> p;
  p->SetOrigin(pGrid->GetCenter());
  p->SetNormal(1,0,0);

  cutter->SetCutFunction(p.GetPointer());
  cutter->SetGenerateTriangles(0);

  cutter->SetInputConnection(0, reader->GetOutputPort());
  cutter->Update();

  vtkPolyData* output = vtkPolyData::SafeDownCast(cutter->GetOutputDataObject(0));
  if (output->GetNumberOfCells() != 2)
    {
    printf("Expected 2 but found %d cells in intersected polyhedron\n", output->GetNumberOfCells());
    return 1;
    }

  return 0; // success
}
