# Are My Plants Safe?

## Author
- **Full Name:** Jacob Buhler

## Files and Directories
- `weather.csv`: Contains historical weather data from 2014 to 2024 for Bangor, California.
- `list.h`: Header file for the linked list of maps which organizes the weather data.
- `list.cpp`: Implements the linked list, including methods for data analysis and manipulation.
- `main.cpp`: Main executable file. Handles input, error detection, and method invocations.
- `weather.h`: Defines a struct for organizing the weather data attributes.
- `misc.cpp`: Includes various utility functions for printing outputs and handling errors.
- `misc.h`: Header file for miscellaneous utility functions.
- `Makefile`: Script for compiling the project. Run using `make` command.

## Overview
This project analyzes historical weather data to determine the average month in which harmful insects become active, providing valuable insights to local farmers and gardeners in Bangor, California.

## Project Description
Focused on the crucial question of pest activity timing, this research explores: "In which month do harmful insects typically become active in Bangor, California?" Understanding this timing is vital for effective crop protection and gardening strategies.

## Research Question
- What is the average month in which harmful insects that affect plants and crops start to become active in Bangor, California?

## Stakeholders
- Local Farmers: Can plan their planting and pest control measures more effectively.
- Home Gardeners: Gain insights on protective measures to ensure the health of their gardens.

## Problem-Solving Approach
- **Data Analysis:** The project involves analyzing weather patterns over a decade to predict insect activity.
- **Key Variables:** The primary variable considered is the minimum temperature (TMIN), which correlates with insect emergence patterns.
- **ADT Selection:** A linked list of maps was chosen for efficient data insertion and retrieval, crucial for handling large datasets and facilitating quick searches.

## Usage Instructions

### Compilation
- **Compile the project:** Use the provided Makefile by running the command `make`. This will compile all the source files and create an executable.

### Execution
- **Run the program:** After compilation, execute the program by running `./main` in the terminal.

By following these instructions, users can easily compile and run the application to analyze the historical weather data and understand the patterns related to harmful insect activity.
