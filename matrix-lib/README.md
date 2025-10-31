# s21_matrix Library Implementation

## Overview
Developed a comprehensive C library for numerical matrix operations, implementing fundamental linear algebra functionalities with strict adherence to mathematical principles and computational accuracy.

## Core Functionality

### Matrix Structure and Memory Management
**Matrix Creation (`s21_create_matrix`)**
- Implemented dynamic memory allocation for matrix data structure
- Added validation for row and column parameters (positive integers)
- Established robust error handling for memory allocation failures
- Initialized matrix elements to zero for consistency

**Matrix Cleanup (`s21_remove_matrix`)**
- Developed safe memory deallocation system
- Implemented pointer nullification after cleanup
- Added protection against double-free errors
- Ensured complete resource liberation

### Matrix Comparison and Validation
**Equality Check (`s21_eq_matrix`)**
- Implemented dimensional compatibility verification
- Developed precise element-wise comparison with 7-decimal-place accuracy
- Added tolerance-based floating-point comparison to handle precision limitations
- Optimized performance with early termination on mismatch detection

### Basic Arithmetic Operations
**Matrix Addition (`s21_sum_matrix`)**
- Implemented element-wise addition with dimensional validation
- Added overflow/underflow detection for numerical stability
- Developed result matrix allocation and initialization

**Matrix Subtraction (`s21_sub_matrix`)**
- Created element-wise subtraction with proper error handling
- Implemented dimensional compatibility checks
- Added comprehensive input validation

**Scalar Multiplication (`s21_mult_number`)**
- Developed efficient scalar multiplication algorithm
- Implemented proper handling of special values (zero, negative numbers)
- Added validation for numerical stability

**Matrix Multiplication (`s21_mult_matrix`)**
- Implemented standard matrix multiplication algorithm with O(n³) complexity
- Added dimensional compatibility verification (columns of A == rows of B)
- Developed efficient nested loop structure for optimal performance
- Implemented proper error handling for size mismatches

### Advanced Matrix Operations
**Matrix Transposition (`s21_transpose`)**
- Implemented efficient row-column swapping algorithm
- Developed memory-optimized transposition for large matrices
- Added validation for input matrix integrity

**Determinant Calculation (`s21_determinant`)**
- Implemented recursive Laplace expansion for determinant computation
- Added base cases for 1x1 and 2x2 matrices for optimization
- Developed efficient minor calculation and caching
- Added validation for square matrix requirement

**Matrix of Algebraic Complements (`s21_calc_complements`)**
- Implemented minor calculation through submatrix extraction
- Developed sign pattern application for cofactor matrix
- Added efficient algebraic complement computation
- Implemented validation for square matrices

**Matrix Inversion (`s21_inverse_matrix`)**
- Developed comprehensive inverse calculation using adjugate method
- Implemented determinant-based singularity check
- Added transposition of cofactor matrix
- Implemented scalar multiplication by 1/determinant
- Added special case handling for non-invertible matrices

## Technical Implementation Details

### Error Handling System
- Comprehensive error codes: 0 (OK), 1 (incorrect matrix), 2 (calculation error)
- Consistent error reporting across all functions
- Input validation for null pointers, invalid dimensions, and memory allocation
- Boundary checking for matrix indices and operations

### Memory Management
- Efficient dynamic memory allocation with proper alignment
- Memory leak prevention through rigorous cleanup procedures
- Optimized memory usage for large matrix operations
- Safe reallocation strategies for resizing operations

### Numerical Precision and Stability
- Implemented floating-point comparison with configurable epsilon
- Added checks for numerical overflow and underflow
- Developed stable algorithms for determinant and inverse calculations
- Implemented proper handling of near-singular matrices

### Performance Optimization
- Efficient algorithm selection for each operation type
- Memory access pattern optimization for cache efficiency
- Loop unrolling and vectorization where applicable
- Early termination in comparison and validation functions

## Testing and Quality Assurance

### Unit Test Coverage
- Developed extensive test suite using Check framework
- Achieved over 80% code coverage verified with gcov
- Created test cases for all boundary conditions and edge cases
- Implemented randomized testing for statistical validation

### Test Categories
**Basic Operations**
- Creation and destruction tests
- Memory allocation validation
- Basic arithmetic operation verification

**Mathematical Correctness**
- Determinant calculation accuracy
- Inverse matrix validation (A × A⁻¹ = I)
- Transposition property verification
- Algebraic complement correctness

**Error Conditions**
- Invalid input handling
- Dimension mismatch scenarios
- Memory allocation failure recovery
- Numerical stability under extreme values

### Build System and Automation
**Makefile Implementation**
- `all`: Complete build including library and tests
- `clean`: Thorough cleanup of all generated files
- `test`: Test execution with coverage reporting
- `s21_matrix.a`: Static library compilation
- `gcov_report`: HTML coverage report generation

**Continuous Integration**
- Automated testing pipeline
- Coverage threshold enforcement
- Memory leak detection integration
- Performance benchmarking

## Key Features and Innovations

### Mathematical Rigor
- Strict adherence to linear algebra principles
- Proper handling of special matrix types (diagonal, identity, triangular)
- Accurate implementation of mathematical formulas and algorithms

### API Design
- Consistent function naming and parameter ordering
- Clear documentation for each function's purpose and limitations
- Intuitive error code system for easy debugging
- Comprehensive input validation

### Cross-Platform Compatibility
- Strict C11 standard compliance
- POSIX.1-2017 compatibility
- Google style guide adherence
- Portable memory management techniques

### Performance Characteristics
- Optimized algorithms for common use cases
- Efficient memory usage patterns
- Scalable performance with matrix size
- Minimal computational overhead