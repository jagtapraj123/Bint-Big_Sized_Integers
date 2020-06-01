# Bint (Big Sized Integer)

**bint** is a c++ class which is designed to overcome the limitations of integers.

## Table of Contents
- [Bint (Big Sized Integer)](#bint-big-sized-integer)
  - [Table of Contents](#table-of-contents)
  - [Overview](#overview)
  - [Installation](#installation)
  - [Usage](#usage)
    - [Initialization](#initialization)
    - [Arithmatic Operations](#arithmatic-operations)
    - [Comprisons](#comprisons)
    - [Print](#print)
    - [Extras](#extras)
  - [Contributing](#contributing)
  - [License](#license)

## Overview

General integers are of 32-bits size. Long integer are of 64-bit size. 
These integers are stored in 32-bit or 64-bit registers while computations. Hence they are of limited size.

Signed 32-bit integer can take value between <img src="https://render.githubusercontent.com/render/math?math=$-(2^{32-1}-1)$"> and <img src="https://render.githubusercontent.com/render/math?math=$(2^{32-1}-1)$"> i.e. <img src="https://render.githubusercontent.com/render/math?math=$-2,147,483,647$"> and <img src="https://render.githubusercontent.com/render/math?math=$2,147,483,647$">. But 2 billion is not a big value while doing scientific calculations.

We can use float or double which can go upto larger range. But float operations are more computationally expensive (takes more time) and converting value to to floating looses precision.

Hence, I have created **bint**, a new datatype which has all the operations as an int. But the bint can take integer value between <img src="https://render.githubusercontent.com/render/math?math=$-10^{(9^{(2^{(31)}-1)})}$"> and <img src="https://render.githubusercontent.com/render/math?math=$10^{(9^{(2^{(31)}-1)})}$">.

## Installation

Download the file [Bint.cpp](https://github.com/jagtapraj123/Bint-Big_Sized_Integers/blob/master/Bint.cpp) and it to working directory of your project.

Include Bint.cpp to your main.cpp file and you are good to go.
```c++
#include "Bint.cpp"
```

## Usage

### Initialization
bint can be initialised using 
1. int
2. long int
3. long long int
4. string.

```c++
int p = 545646;
bint a = bint(p);

string q = "26534186";
bint b = bint(q);
```
### Arithmatic Operations

All arithmatic operations are possible in bint.
1. \+
2. \-
3. \*
4. \/

```c++
1. bint c = a + b;
2. bint d = a - b;
3. bint e = a * b;
4. bint f = a / b;
```

All arithmatic operations can be of following type:
```c++
1. bint (op) bint
2. bint (op) int
3. bint (op) long int
4. bint (op) long long int
5. bint (op) string
```

### Comprisons
All types of comparisons are possible in bint.
1. \==
2. \!=
3. \>
4. \>=
5. \<
6. \<=

All coparisons can be of following types:
```c++
1. bint (comp) bint
2. bint (comp) int
3. bint (comp) long int
4. bint (comp) long long int
5. bint (comp) string
```

### Print
```c++
bint.print();
```

### Extras

I really like to use ++ and -- for incrementing or decrementing value by 1. Hence I added these in bint class.

```c++
bint a = bint(p);
a++;
++a;

bint b = bint(q);
b--;
--b;
```

Prefix and Postfix notations works same as it does in int.


<!-- ## Official Documentation -->


## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

I need help in setting operator precedance.

I really need some help for decoding complex equations.


## License
[MIT](https://github.com/jagtapraj123/Bint-Big_Sized_Integers/blob/master/LICENSE)

