[Mesh]
        [disc]
        type = FileMeshGenerator
        file = untitled.msh
        []
[]

[Variables]
        [T]
        []
[]

[Kernels]
        [diff]
        type = ADDiffusion
        variable = T
        []
[]

[BCs]
        [insulation]
        type = ADNeumannBC
        variable = T
        boundary = 'insulated'
        value = 0        
        []
        [left]
        type = ADNeumannBC
        variable = T
        boundary = 'top'
        value = 10      
        []
        [right]
        type = ADNeumannBC
        variable = T
        boundary = 'left'
        value = -10     
        []
        [top]
        type = ADNeumannBC
        variable = T
        boundary = 'bottom'
        value =0      
        []
        [bottom]
        type = ADNeumannBC
        variable = T
        boundary = 'right'
        value =0 
        []
[]


[Executioner]
  type = Steady

  # Preconditioned JFNK (default)
  solve_type = 'Newton'

  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
[]
