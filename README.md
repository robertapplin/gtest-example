## Building instructions

Create a conda environment using the `environment.yml` file in this repo:

```sh
conda env create -f environment.yml
```

Activate the environment:

```sh
conda activate dev-env
```

Configure and generate your build files from the source directory:

```sh
cmake --preset=ninja .
```

Navigate to your build directory and build the project:

```sh
cd ../build && ninja
```

Run the test python script:

```sh
PYTHONPATH=$PWD/ python ../boost-example/test.py
```
