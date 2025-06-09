# Computer Science Implementations

This repository contains a collection of computer science implementations in C, designed for clarity, correctness, and testability. All code is thoroughly unit tested using the [Unity Test Framework](https://github.com/ThrowTheSwitch/Unity), which is included as a git submodule.

## Project Structure

- `src/` – Source code for algorithms and data structures
- `test/` – Unit tests for the implementations
- `unity/` – Unity Test Framework (as a submodule)
- `build/` – Build artifacts (ignored by git)
- `Makefile` – Build, test, and clean commands

## Getting Started

### 1. Clone the repository

```sh
git clone https://github.com/eujuliu/computer_science_implementations
cd computer_science_implementations
```

### 2. Initialize and update submodules

Unity is included as a git submodule. After cloning (or when updating Unity), run:

```sh
git submodule update --init --recursive
```

### 3. Build, Test, and Clean

The provided `Makefile` supports the following commands:

- **Build the project:**
  ```sh
  make build
  ```
- **Run all tests:**
  ```sh
  make test
  ```
- **Clean build artifacts:**
  ```sh
  make clean
  ```

## Notes

- All test results and build outputs are placed in the `build/` directory.
- The project is cross-platform and should work on Linux, macOS, and Windows (with a compatible shell and GCC).

## License

See [LICENSE](https://github.com/eujuliu/computer_science_implementations/blob/main/LICENSE) for details.
