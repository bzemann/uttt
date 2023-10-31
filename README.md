# UTTT

## Setting up

### Git repository
Clone the repository using ssh
```sh
git clone git@gitlab.ethz.ch:uttt/uttt.git
```

After cloning you still have to initalize the submodules (the dependencies)
```sh
cd uttt
git submodule init
git submodule update
```

### CMake

Either use an IDE like CLion or use cmake and make directly in the terminal.
```sh
mkdir build
cmake -B build
make -C build
```

CMake also exports compile commands, meaning language servers like clangd just work.

Now you're setup!

