# Shortest Path Airline Route Finder

This is a C++ command-line tool that calculates the shortest flight path and total distance between any two airports from a given airline network.

It implements Dijkstra's algorithm to find the most efficient route.

## Features

* **Shortest Path Calculation:** Finds the shortest possible travel distance between a start and end airport.
* **Dijkstra's Algorithm:** Uses a min-priority queue (`std::priority_queue`) for efficient shortest-path computation.
* **Data Parsing:** Reads flight connections from `airline_distances.txt` to build an in-memory graph of the airline network.

## Getting Started

### Prerequisites

* A C++ compiler (like `g++` or `clang++`)
* The `airline_distances.txt` file in the same directory as the executable.

### Compilation

1.  **Clone the repository:**
    ```sh
    git clone [https://github.com/YOUR_USERNAME/YOUR_REPOSITORY_NAME.git](https://github.com/YOUR_USERNAME/YOUR_REPOSITORY_NAME.git)
    cd YOUR_REPOSITORY_NAME
    ```

2.  **Compile the program:**
    ```sh
    g++ shortest_path.cpp -o shortest_path -std=c++11
    ```
    *(This creates an executable file named `shortest_path`.)*

### Running the Program

1.  **Run the executable:**
    ```sh
    ./shortest_path
    ```

2.  **Follow the prompts:**
    The program will ask you to enter the numeric **Airport ID** for the start and end airports.

    **Example Usage:**
    ```
    Enter the start airport ID: 12087
    Enter the end airport ID: 3469
    A shortest path is 12087 -> 3043 -> 3382 -> 3364 -> 3469
    Total distance: 14293 km.
    ```

## Data Files

* **`airline_distances.txt` (Required):** This file contains the airline network data. Each line represents a one-way flight and is formatted as:
    `[Source_ID] [Destination_ID] [Distance]`
