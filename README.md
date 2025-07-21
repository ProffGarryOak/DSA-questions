# LeetCode Question to C++ File Generator

This Python script automates the creation of C++ files for LeetCode questions, including:
- Fetching the question description from a LeetCode URL
- Creating a folder named `DayN` based on the current date (starting from 21-07-2025 as Day1)
- Saving the question description as comments at the top of the `.cpp` file
- (Optional) You can extend the script to include your solution and a runner for sample test cases

## How It Works
1. Run the script: `python leetcode_to_cpp.py`
2. Enter the LeetCode question URL when prompted
3. The script will:
    - Fetch the question title and description
    - Create a folder named `DayN` (N = days since 21-07-2025)
    - Save a `.cpp` file named after the question in the folder, with the description as comments
4. You can manually add your solution code and a runner to the generated file

## Requirements
- Python 3.x
- `requests` library: `pip install requests`

## Example
```
python leetcode_to_cpp.py
Enter LeetCode question URL: https://leetcode.com/problems/set-matrix-zeroes/
Created Day1/Set Matrix Zeroes.cpp
```

## Customization
- Change the start date by editing `START_DATE` in the script
- Extend the script to prompt for your solution code and add a runner

## License
MIT
