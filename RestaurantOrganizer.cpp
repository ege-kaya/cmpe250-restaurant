/*
Student Name: Ege Can Kaya
Student Number: 2018400018
Project Number: 2
Compile Status: SUCCESS
Running Status: SUCCESS
Notes: didn't implement heapUp because it wasn't necessary
*/
#include "RestaurantOrganizer.h"

using namespace std;

void buildHeap(RestaurantOrganizer& rest);

RestaurantOrganizer::RestaurantOrganizer(const vector<int>& tableCapacityInput){
    numberOfTables = tableCapacityInput.size();
    // write the table ids and capacities into respective arrays as they come
    for(int i=0;i<numberOfTables;i++){
        tableCapacity[i] = tableCapacityInput[i];
        heap[i] = i;
    }
    // call the buildHeap function to organize the randomly ordered arrays
    buildHeap(*this);
}

// start percolating down from the second-to lowest level in order to attain the correct heap structure
void buildHeap (RestaurantOrganizer& rest) {
    for (int i = (rest.numberOfTables-2)/2; i>=0;i--) {
        rest.heapDown(i);
    }
}

// if not even the largest table can take the group, print -1
// otherwise, print the largest table's id, then modify its capacity appropriately
// then percolate down from the root to attain the correct heap structure
void RestaurantOrganizer::addNewGroup(int groupSize, ofstream& outFile){
    if(groupSize > tableCapacity[0]) {
        outFile << "-1" << std::endl;
    } else {
        tableCapacity[0] -= groupSize;
        outFile << heap[0] << std::endl;
        heapDown(0);
    }
}

// no need to use this because there are no insert operations and buildHeap does all the necessary initial work
// keep it since it's in the header file
void RestaurantOrganizer::heapUp(int index){

}

// just do the percolate down procedure from the given index, like we saw in class
// create a hole in the given index, don't forget its value, then move the hole down until you find a suitable spot
void RestaurantOrganizer::heapDown(int index){
    int hole = index;
    // we shouldn't forget the capacity and id of the node where we create the hole!
    int tempCap = tableCapacity[index];
    int tempNo = heap[index];
    // make sure to go down until you hit a leaf node
    while((hole*2)+1 <= numberOfTables-1) {
        // hole has 2 children
        if (hole*2+2 <= numberOfTables-1) {
            int biggerChildIndex;
            // find the index of the bigger child, in case of equality take the one with the lower id
            if (tableCapacity[2*hole+1] > tableCapacity[2*hole+2]) {
                biggerChildIndex = 2*hole+1;
            } else if (tableCapacity[2*hole+1] == tableCapacity[2*hole+2]) {
                biggerChildIndex = heap[2*hole+1] < heap[2*hole+2] ? 2*hole+1 : 2*hole+2;
            } else {
                biggerChildIndex = 2*hole+2;
            }
            // then compare the parent and the bigger child and move hole down if necessary
            if ((tableCapacity[biggerChildIndex] > tempCap) || ((tableCapacity[biggerChildIndex] == tempCap) && heap[biggerChildIndex] < tempNo)) {
                tableCapacity[hole] = tableCapacity[biggerChildIndex];
                heap[hole] = heap[biggerChildIndex];
                hole = biggerChildIndex;
            } else { // if the parent needs not move down quit the while loop because we found our spot
                break;
            }
        }
        // hole has 1 child
        else {
            int childIndex = 2*hole+1;
            // compare child with parent
            if((tableCapacity[childIndex] > tempCap) || ((tableCapacity[childIndex] == tempCap) && heap[childIndex] < tempNo)) {
                tableCapacity[hole] = tableCapacity[childIndex];
                heap[hole] = heap[childIndex];
                hole = childIndex;
            } else { // if the parent needs not move down quit the while loop because we found our spot
                break;
            }
        }
    }
    // quitting the loop means we found our spot to plug in whatever value was written where we created the hole
    tableCapacity[hole] = tempCap;
    heap[hole] = tempNo;
}



// print whatever's at the root since it's the largest one, then remove it and percolate down from the root.
// repeat until each table capacity is printed
void RestaurantOrganizer::printSorted(ofstream& outFile){
    int lastIndex = numberOfTables-1;
    for(int i = 0; i < numberOfTables; i++) {
        int cap = tableCapacity[0];
        if (cap != -1)
        outFile << cap << " ";
        tableCapacity[0] = tableCapacity[lastIndex];
        tableCapacity[lastIndex] = -1;
        heap[0] = heap[lastIndex--];
        heapDown(0);
    }
}



// YOU CAN ADD YOUR HELPER FUNCTIONS

