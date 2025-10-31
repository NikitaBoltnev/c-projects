# s21_decimal Library Implementation

## Overview

Developed a comprehensive decimal arithmetic library in C that provides precise financial calculations by implementing a custom decimal floating-point type. The library addresses the limitations of native floating-point types in financial applications where rounding errors are unacceptable.

## Core Functionality

### Decimal Type Implementation
- Created a custom `s21_decimal` data structure with 128-bit binary representation
- Implemented sign bit handling, 96-bit integer component, and scaling factor management
- Supported decimal numbers range: -79,228,162,514,264,337,593,543,950,335 to +79,228,162,514,264,337,593,543,950,335
- Designed efficient bit manipulation algorithms for decimal operations

### Arithmetic Operations
**Addition (`s21_add`)**
- Implemented precise decimal addition with proper scaling alignment
- Added overflow detection and error handling
- Incorporated bank rounding for numbers exceeding mantissa capacity

**Subtraction (`s21_sub`)**
- Developed signed subtraction with scaling factor consideration
- Ensured proper handling of negative results and edge cases

**Multiplication (`s21_mul`)**
- Created efficient multiplication algorithm for 96-bit integers
- Implemented scaling factor adjustment and overflow prevention
- Added precision management for financial calculations

**Division (`s21_div`)**
- Built precise division algorithm with remainder handling
- Implemented division by zero detection and error reporting
- Added scaling factor normalization for accurate results

### Comparison Operations
- **Less than (`s21_is_less`)**: Implemented signed comparison with scaling consideration
- **Less or equal (`s21_is_less_or_equal`)**: Combined less than and equality checks
- **Greater than (`s21_is_greater`)**: Reverse logic of less than comparison
- **Greater or equal (`s21_is_greater_or_equal`)**: Comprehensive greater than or equal evaluation
- **Equal (`s21_is_equal`)**: Bitwise comparison with scaling normalization
- **Not equal (`s21_is_not_equal`)**: Inverse of equality check

### Type Conversion System
**From Integer (`s21_from_int_to_decimal`)**
- Efficient conversion from standard integer types to decimal representation
- Sign handling and zero scaling for integer values

**From Float (`s21_from_float_to_decimal`)**
- Precise conversion of floating-point numbers to decimal format
- Implemented significant digit extraction and rounding
- Added error handling for out-of-range values and special cases (too small/large numbers)

**To Integer (`s21_from_decimal_to_int`)**
- Conversion with fractional part truncation
- Overflow detection and error reporting
- Sign preservation during conversion

**To Float (`s21_from_decimal_to_float`)**
- Accurate conversion maintaining precision within float limitations
- Proper handling of scaling factors and significant digits

### Mathematical Functions
**Floor (`s21_floor`)**
- Rounding toward negative infinity
- Proper handling of negative numbers and fractional parts

**Round (`s21_round`)**
- Banker's rounding implementation
- Nearest integer rounding with tie-breaking rules

**Truncate (`s21_truncate`)**
- Discard fractional digits including trailing zeros
- Maintain integer portion of decimal value

**Negate (`s21_negate`)**
- Sign inversion operation
- Efficient bit manipulation for sign change

## Technical Implementation

### Error Handling System
- Comprehensive error codes: 0 (OK), 1 (overflow), 2 (underflow), 3 (division by zero)
- Consistent error reporting across all functions
- Input validation and boundary checking

### Memory and Performance Optimization
- Efficient bit-level operations using bitwise manipulation
- Minimal memory footprint with optimized data structures
- Fast algorithms for common decimal operations

### Testing and Quality Assurance
- Developed extensive unit test suite using Check framework
- Achieved over 80% code coverage verified with gcov
- Created automated testing pipeline with Makefile
- Generated detailed HTML coverage reports

### Build System
- Comprehensive Makefile with multiple targets:
  - `all`: Complete build including library and tests
  - `clean`: Resource cleanup
  - `test`: Test execution and coverage verification
  - `s21_decimal.a`: Static library compilation
  - `gcov_report`: HTML coverage report generation

## Key Features

### Precision Management
- Maintained exact decimal representation without floating-point errors
- Implemented proper scaling factor handling for fractional values
- Ensured consistent behavior across all arithmetic operations

### Financial Calculation Compliance
- Banker's rounding for minimal rounding bias
- Support for large numbers required in financial applications
- Exact decimal arithmetic without precision loss

### Cross-Platform Compatibility
- Strict C11 standard compliance
- POSIX.1-2017 compatibility
- Google style guide adherence for code consistency