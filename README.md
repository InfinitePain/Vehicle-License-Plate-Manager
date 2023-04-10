# Vehicle License Plate Manager

This repository contains a C++ program developed as an assignment for the "Programmieren 2" course in the Technical Computer Science program at the Augsburg University of Applied Sciences. The goal of the project is to learn and apply the concepts of object-oriented programming, usage of namespaces, the string class, and reference and pointer manipulation. The program is designed to input and evaluate vehicle license plates, as well as manage a simple database for storing them.

## Project Structure

The project consists of three files:

- `kennzeichen.h`: Contains the definition of the vehicle license plate structure and its associated functions.
- `datenbank.h`: Contains the functions necessary for generating and displaying the simple database.
- `main.cpp`: Contains the test functions to be implemented and called in the `main()` function.

## Learning Objectives

The main learning objectives of this project include:

- Getting familiar with the usage of namespaces.
- Taking the first steps in object-oriented programming.
- Using the `string` class and its associated functions to implement the required functionality.
- Reviewing references and pointers.
- Implementing a program for input and evaluation of vehicle license plates.
- Implementing various checks for special types of license plate numbers, such as "Schnapszahlen" (e.g., 11, 22, 33, …, 88, 99, 111, 222, 333,…,999, 1111), tens (e.g., 10, 20, 30, …, 80, 90), hundreds (e.g., 100, 200, 300, …, 800, 900), and thousands (e.g., 1000, 2000, 3000, …, 8000, 9000).

To compile and run the program, follow these steps:

1. Make sure you have a C++ compiler installed (e.g., g++).
2. Open a terminal and navigate to the directory containing the source files (kennzeichen.h, datenbank.h, and main.cpp).
3. Compile the program using the following command:

    ``` 
    g++ -o license_plate_manager main.cpp
    ```

4. Run the compiled program with:

    ``` 
    ./license_plate_manager
    ```

## Contributing

Contributions to this project are welcome. If you have any suggestions for improvements or additional features, please feel free to open an issue or submit a pull request on the project's GitHub repository.

## License

This project is licensed under the Apache 2.0 License. See the LICENSE file for more information.

## Acknowledgments

We would like to thank the instructors and the teaching assistants of the "Programmieren 2" course for their guidance and support throughout the development of this project.

Additionally, we appreciate the contributions of fellow students and open source community members who have provided feedback and suggestions for improvement.

## Disclaimer

This project is meant for educational purposes only. While the program can be used to manage a simple database of vehicle license plates, it is not intended to replace any official systems or be used for any illegal activities. The creators of this project are not responsible for any misuse or consequences resulting from the use of the program.
