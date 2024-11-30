# Superstar Collaboration Matching

This program implements the **Edmonds Blossom Algorithm** to find the maximum matching in a graph. The context is matching superstars who can collaborate, where the input specifies which superstars each superstar can collaborate with. The program determines the maximum number of collaborations.

---

## Features
- Finds the **maximum matching** for a collaboration graph of superstars.
- Handles **blossoms** (odd-length cycles) efficiently using contraction.
- Outputs the matched pairs in the maximum matching.

---

## Requirements
- **C++ Compiler**: Ensure you have a C++ compiler that supports C++11 or later (e.g., `g++`).
- **Standard Library**: No additional dependencies are required.

---

## How to Run

### 1. Compilation
Use a C++ compiler to compile the program:
```bash
g++ -o superstar_matching Bollywood_Superstar_Collaborations.cpp
```
Run the compiled Program 
```bash
./superstar_matching
```

## Input Format

Enter the number of Superstars: 4

No. of superstars 1  can collaborate : 2

Enter the Superstar number : 2

Enter the Superstar number : 3

No. of superstars 2  can collaborate : 2

Enter the Superstar number : 1

Enter the Superstar number : 4

No. of superstars 3  can collaborate : 2

Enter the Superstar number : 1

Enter the Superstar number : 4

No. of superstars 4  can collaborate : 2

Enter the Superstar number : 2

Enter the Superstar number : 3



## Output 

Maximum matching: 2

Matched pairs:

1 -- 2

3 -- 4




# Road Project Management with Minimum Spanning Tree

This project implements a system to manage and prioritize road projects between cities. It uses **Kruskal's Algorithm** with the **Union-Find Data Structure (Union by Size)** to find the **Minimum Spanning Tree (MST)** of the road network. Additionally, it allows searching for a specific road by its name.

---

## Features
1. **Minimum Spanning Tree (MST)**:
   - Calculates the minimum cost of connecting all cities using prioritized road projects.
   - Sorts projects by **priority** (descending) and **cost** (ascending).
2. **Search Functionality**:
   - Search for a specific road by its name in the road project list.
3. **Customizable Input**:
   - Accepts a list of road projects, with each project defined as a tuple of road name, priority, cost, and the two cities it connects.
4. **Road Sorting**:
   - Outputs the list of projects sorted by priority and cost.

---

## Requirements
- **C++ Compiler**: Ensure you have a C++ compiler (e.g., `g++`) that supports C++11 or later.
- **Standard Library**: No external libraries are required.

---

## How to Run

### 1. Compilation
Use a C++ compiler to compile the program:
```bash
g++ -o road_project City_Road_Network_Optimization.cpp
```

Execute
```bash
./road_project
```

## Example input 


Enter the number of tuples: 5

Enter the tuples (RoadName Priority Cost City1 City2):

road1 4 100 A1 A2

road2 3 150 A2 A3

road3 5 200 A3 A4

road4 4 50 A4 A1

road5 5 120 A2 A4



Enter the road you are searching: road4



## Example output

Searching...
road4 found
Searching end...

Minimum number of roads: 3

Sorted tuples:

road3 5 200 A3 A4

road5 5 120 A2 A4

road1 4 100 A1 A2

road4 4 50 A4 A1

road2 3 150 A2 A3




