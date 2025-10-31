# Simple Bash Utils

## Implementation Overview

### Part 1: Custom cat Utility Development

#### Core Functionality Implementation
- Developed a custom `s21_cat` utility replicating core functionality of the standard Unix cat command
- Implemented file content display functionality for single and multiple files
- Added support for concatenating multiple files and displaying their contents sequentially

#### Command Line Options Support
- **-b / --number-nonblank**: Implemented line numbering exclusively for non-empty lines
- **-e / -E**: Added end-of-line character display with `$` marker, including GNU-compatible behavior
- **-n / --number**: Developed comprehensive line numbering for all output lines
- **-s / --squeeze-blank**: Created intelligent multiple blank line compression algorithm
- **-t / -T**: Implemented tab character visualization as `^I` with proper GNU compatibility

#### Technical Implementation Details
- Structured C code following Google style guidelines and C11 standard
- Implemented efficient file I/O operations with proper error handling
- Developed modular code architecture with separate functions for each option
- Added comprehensive input validation and error reporting
- Created Makefile with proper build targets and dependency management

### Part 2: Basic grep Utility Implementation

#### Core Pattern Matching Engine
- Developed `s21_grep` utility with fundamental pattern searching capabilities
- Implemented regular expression support using standard regex libraries
- Added file processing functionality for single and multiple file inputs

#### Essential Flag Support
- **-e pattern**: Implemented explicit pattern specification
- **-i**: Developed case-insensitive matching functionality
- **-v**: Created inverted match filtering system
- **-c**: Added match counting with line aggregation
- **-l**: Implemented filename-only output for matching files
- **-n**: Developed line numbering system for matched results

#### Search Algorithm Implementation
- Built efficient string matching algorithms with regex integration
- Implemented file reading and line-by-line processing
- Added support for multiple patterns and files in single execution
- Developed proper output formatting according to Unix grep standards

### Part 3: Advanced grep Features (Bonus)

#### Extended Flag Implementation
- **-h**: Developed filename suppression in multi-file searches
- **-s**: Implemented silent error handling for unreadable files
- **-f file**: Created pattern file reading functionality
- **-o**: Added matched parts extraction and display

#### Enhanced Pattern Management
- Implemented pattern loading from external files
- Developed efficient pattern storage and matching system
- Added support for complex regex patterns from file sources
- Created optimized output for extracted match segments

### Part 4: Flag Combination Support (Bonus)

#### Complex Flag Interactions
- Implemented all possible two-flag combinations (e.g., `-iv`, `-in`, `-vc`)
- Developed intelligent flag precedence and interaction handling
- **-i -v combination**: Case-insensitive inverted matching
- **-i -n combination**: Case-insensitive search with line numbers
- **-c -l combination**: Count reporting with filename-only output
- **-v -n combination**: Inverted matching with line numbering

#### Advanced Combination Logic
- Created unified flag processing system handling all permutations
- Implemented efficient algorithm for combined flag behaviors
- Developed comprehensive testing for all flag interaction scenarios
- Ensured consistent behavior with standard grep utility

### Technical Excellence

#### Code Quality and Standards
- Strict adherence to C11 standard and POSIX.1-2017 compliance
- Google style code formatting throughout the project
- Modular architecture with clear separation of concerns
- Comprehensive error handling and edge case management

#### Build System and Testing
- Implemented robust Makefile with proper targets and dependencies
- Created extensive integration tests comparing with native utilities
- Developed automated testing for all flag combinations and edge cases
- Ensured identical behavior with standard bash utilities

#### Performance Optimization
- Efficient memory management and file I/O operations
- Optimized pattern matching algorithms
- Minimal resource consumption during execution
- Fast processing even with large files and complex patterns