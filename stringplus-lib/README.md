# s21_string+ Library Implementation

## Overview
Developed a comprehensive C library implementing the standard string.h functionality with additional custom string processing features, including partial implementations of sprintf and sscanf functions.

## Core string.h Functionality Implementation

### Memory Manipulation Functions
**Memory Search (`s21_memchr`)**
- Implemented byte-by-byte search in memory blocks
- Added boundary checking and null pointer validation
- Optimized for performance with efficient loop structure

**Memory Comparison (`s21_memcmp`)**
- Developed byte-wise comparison algorithm
- Implemented early termination on mismatch detection
- Added comprehensive error handling

**Memory Copy (`s21_memcpy`)**
- Created efficient memory block copying
- Implemented overlap detection and handling
- Added size validation and boundary checks

**Memory Set (`s21_memset`)**
- Developed fast byte filling algorithm
- Implemented optimized pattern application
- Added validation for input parameters

### String Manipulation Functions
**String Concatenation (`s21_strncat`)**
- Implemented safe string concatenation with size limits
- Added null-termination guarantee
- Developed efficient length calculation and copying

**String Search (`s21_strchr`, `s21_strrchr`)**
- Created forward and reverse character search algorithms
- Implemented null terminator handling
- Added comprehensive test coverage for edge cases

**String Comparison (`s21_strncmp`)**
- Developed limited-length string comparison
- Implemented early termination optimization
- Added special character handling

**String Copy (`s21_strncpy`)**
- Created safe string copying with size limits
- Implemented padding and truncation handling
- Added null-termination management

**String Span (`s21_strcspn`)**
- Developed character set exclusion algorithm
- Implemented efficient search and termination
- Added validation for input strings

**String Search (`s21_strpbrk`)**
- Created character set search implementation
- Implemented first match detection
- Added comprehensive error handling

**Substring Search (`s21_strstr`)**
- Developed efficient substring search algorithm
- Implemented needle validation and empty string handling
- Added performance optimization for large strings

**String Tokenization (`s21_strtok`)**
- Created stateful tokenization implementation
- Implemented delimiter handling and state preservation
- Added thread safety considerations

### Utility Functions
**String Length (`s21_strlen`)**
- Implemented efficient string length calculation
- Added null pointer validation
- Optimized for performance

**Error Message (`s21_strerror`)**
- Developed platform-specific error message arrays
- Implemented OS detection using preprocessor directives
- Added error code validation and bounds checking

## sprintf Function Implementation

### Core Formatting Engine
- Developed variable argument processing system
- Implemented format string parsing with specifier detection
- Added support for flags, width, precision, and length modifiers

### Supported Specifiers
**Character (`%c`)**
- Implemented character output with padding
- Added width and alignment handling
- Developed precision ignore logic

**Signed Integer (`%d`)**
- Created signed integer formatting
- Implemented flag handling (+, space, -)
- Added width and precision support

**Floating Point (`%f`)**
- Developed decimal floating point formatting
- Implemented precision control (default 6 digits)
- Added special value handling (NaN, infinity)

**String (`%s`)**
- Created string output with truncation support
- Implemented precision-based length limiting
- Added padding and alignment

**Unsigned Integer (`%u`)**
- Developed unsigned integer formatting
- Implemented width and precision handling
- Added flag compatibility

**Percent Literal (`%%`)**
- Created literal percent character output
- Implemented flag and modifier ignore logic

### Format Modifier Support
**Flags**
- `-` Left alignment implementation
- `+` Force sign display
- ` ` Space for positive numbers

**Width Specification**
- Fixed width with number specification
- Padding with spaces or zeros
- Minimum output width enforcement

**Precision Control**
- `.number` precision specification
- Digit counting for integers
- Decimal place control for floats

**Length Modifiers**
- `h` short integer support
- `l` long integer support

## Special String Processing Functions

### Case Conversion
**Uppercase Conversion (`s21_to_upper`)**
- Implemented locale-aware uppercase conversion
- Added memory allocation and error handling
- Developed efficient character processing

**Lowercase Conversion (`s21_to_lower`)**
- Created comprehensive lowercase transformation
- Implemented special character handling
- Added null terminator preservation

### String Manipulation
**String Insertion (`s21_insert`)**
- Developed safe string insertion at specified index
- Implemented bounds checking and index validation
- Added memory allocation with error recovery

**String Trimming (`s21_trim`)**
- Created leading and trailing character removal
- Implemented custom character set specification
- Added empty string and edge case handling

## Technical Implementation Details

### Memory Management
- Comprehensive null pointer validation across all functions
- Safe memory allocation with proper error handling
- Efficient buffer management for string operations
- Memory leak prevention through careful resource management

### Error Handling
- Consistent error code return system
- Comprehensive input validation
- Graceful failure recovery
- Platform-specific error message implementation

### Performance Optimization
- Efficient algorithm selection for each operation
- Minimized memory allocations and copies
- Optimized loop structures and early termination
- Cache-friendly memory access patterns

### Testing and Quality Assurance
**Unit Test Coverage**
- Developed extensive test suite using Check framework
- Achieved over 80% code coverage verified with gcov
- Created comparative tests against standard library implementations
- Implemented boundary condition and edge case testing

**Test Categories**
- Functional correctness verification
- Memory management validation
- Error condition handling
- Performance benchmarking
- Cross-platform compatibility

### Build System
**Makefile Implementation**
- `all` - Complete library and test build
- `clean` - Thorough cleanup procedure
- `test` - Test execution with coverage reporting
- `s21_string.a` - Static library compilation
- `gcov_report` - HTML coverage report generation

## Key Features and Innovations

### Standards Compliance
- Strict adherence to C11 standard and POSIX.1-2017
- Complete compatibility with standard string.h interface
- Consistent behavior with reference implementations

### Code Quality
- Google style guide compliance
- Structured programming principles
- Comprehensive documentation
- Modular architecture with minimal code duplication

### Cross-Platform Support
- Platform-specific error message implementations
- OS detection using preprocessor directives
- Portable memory management techniques
- Consistent behavior across different environments