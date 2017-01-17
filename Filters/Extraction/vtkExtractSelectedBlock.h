/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkExtractSelectedBlock.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
/**
 * @class   vtkExtractSelectedBlock
 *
*/

#ifndef vtkExtractSelectedBlock_h
#define vtkExtractSelectedBlock_h

#include "vtkFiltersExtractionModule.h" // For export macro
#include "vtkExtractSelectionBase.h"

class VTKFILTERSEXTRACTION_EXPORT vtkExtractSelectedBlock : public vtkExtractSelectionBase
{
public:
  static vtkExtractSelectedBlock* New();
  vtkTypeMacro(vtkExtractSelectedBlock, vtkExtractSelectionBase);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;

protected:
  vtkExtractSelectedBlock();
  ~vtkExtractSelectedBlock() VTK_OVERRIDE;

  // Generate the output.
  int RequestData(vtkInformation *,
    vtkInformationVector **, vtkInformationVector *) VTK_OVERRIDE;

  /**
   * Sets up empty output dataset
   */
  int RequestDataObject(vtkInformation* request,
                                vtkInformationVector** inputVector,
                                vtkInformationVector* outputVector) VTK_OVERRIDE;

  int FillInputPortInformation(int port, vtkInformation* info) VTK_OVERRIDE;
private:
  vtkExtractSelectedBlock(const vtkExtractSelectedBlock&) VTK_DELETE_FUNCTION;
  void operator=(const vtkExtractSelectedBlock&) VTK_DELETE_FUNCTION;

};

#endif


