#include <chrono>
#include <iostream>
#include <list>
#include <sstream>
#include <vector>

// High resolution clock is used for performance testing.
using std::chrono::high_resolution_clock;

#define TESTLIST 0
#define TESTRESERVE 0
#define TESTRANDOMINSERTION 0

int main() {

#if TESTLIST
  std::list<int> numbers;
#else
  std::vector<int> numbers;
#if TESTRESERVE
  numbers.reserve(1000000);
#endif
#endif

  // Start performance timing
  high_resolution_clock::time_point start = high_resolution_clock::now();

  // Insert values into the collection
  for (int i = 0; i < 1000000; ++i) {
    numbers.push_back(i);
  }

  // End performance timing for insertion.
  {
    high_resolution_clock::time_point end = high_resolution_clock::now();
    std::chrono::duration<double> timeSpan =
        std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
    std::cout << "Insertion operation took " << timeSpan.count() << " seconds." << std::endl;
    start = end;
  }

  // Iterate through and modify the values in the collection
#if TESTLIST
  for (int &i : numbers) {
    ++i;
  }
#else
  for (size_t i{0}; i < 1000000; ++i) {
    ++numbers[i];
  }
#endif

  // End performance timing for iteration.
  {
    high_resolution_clock::time_point end = high_resolution_clock::now();
    std::chrono::duration<double> timeSpan =
        std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
    std::cout << "Iteration operation took " << timeSpan.count() << " seconds." << std::endl;
    start = end;
  }

  // Random access read values from random locations in the collection.
  int locations[] = {1, 77, 9998, 343, 22, 67, 45};
  for (int rep = 0; rep < 1000; ++rep) {
#if not TESTRANDOMINSERTION
    for (int i : locations) {
#if TESTLIST
      // Get the iterator and move it to the index location to read the value.
      auto numIterator = numbers.begin();
      // Must manually move the iterator and ensure it is not moved off the end of the list.
      while (i > 0 && numIterator != numbers.end()) {
        numIterator++;
        --i;
      }
      int val = *numIterator;
#else
      int val = numbers[i];
#endif
      if (val == 0) {
        std::cout << "Something wrong!";
      }
    }
#else

// The random insertion test inserts a new value at the specified position, retaining all other
// values in the collection.
    for (int i : locations) {
      // Iterator is required for insert for both list and vector.
      auto numIterator = numbers.begin();
#if TESTLIST
      // Must manually move the iterator and ensure it is not moved off the end of the list.
      while (i > 0 && numIterator != numbers.end()) {
        numIterator++;
        --i;
      }
#else
      // Can use pointer addition semantics with vector iterator.
      numIterator += i;
#endif
      numbers.insert(numIterator, *numIterator + 1);
    }
#endif
  }

  // End performance timing
  high_resolution_clock::time_point end = high_resolution_clock::now();
  std::chrono::duration<double> timeSpan =
      std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
  std::cout << "Random " <<
#if TESTRANDOMINSERTION
               "insertion"
#else
               "access"
#endif
               << " operation took " << timeSpan.count() << " seconds." << std::endl;
  return 0;
}
