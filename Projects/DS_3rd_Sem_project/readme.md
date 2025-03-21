# 🌦 Weather Data Analysis System

## 📌 Project Overview
The **Weather Data Analysis System** is a C++ program designed to store, analyze, and retrieve weather records efficiently. It allows users to dynamically add weather data, analyze trends, compute key statistics, and detect anomalies. The system provides insights into temperature variations and patterns through statistical computations and trend analysis.

## 🎯 Features
- **View Weather Records**: Retrieve and display stored weather data.
- **Add Records Dynamically**: Enter new weather data (temperature, date, etc.).
- **Analyze Weather Trends**: Observe daily and overall weather patterns.
- **Compute Statistics**: Calculate maximum, minimum, and average temperatures.
- **Detect Outliers**: Identify anomalies in temperature records.
- **Save Data to File**: Store records for future use.
- **Exit System**: Gracefully terminate the application.

## 🏗 Project Structure
### 📂 Directories & Files
```
SEP/                   # Root of the project
│── data/                # Contains CSV weather records
│── include/             # Header files (.h)
│── src/                 # Source files (.cpp)
│   │── DataRetriever.cpp  # Handles data retrieval from CSV
│   │── Date.cpp           # Manages date parsing and formatting
│   │── main.cpp           # Entry point of the program
│   │── MaxHeap.cpp        # Heap structure for max temperature retrieval
│   │── MinHeap.cpp        # Heap structure for min temperature retrieval
│   │── OutlierAnalysis.cpp # Detects anomalies in weather data
│   │── StatsAnalysis.cpp  # Computes max, min, and avg temperatures
│   │── TrendAnalysis.cpp  # Analyzes daily/overall weather trends
│── UML/                 # Contains UML diagrams for system design
│── CMakeLists.txt       # CMake build configuration
```

## ⚙️ System Architecture
```
+--------------------------------------------------------+
|                Weather Data Analysis System            |
|                                                        |
|   +------------+        +-------------------------+    |
|   |            |        |                         |    |
|   |   User     | ------>|  View Weather Records   |    |
|   |            |        |                         |    |
|   +------------+        +-------------------------+    |
|        |                          |                    |    
|        |                          |                    |    
|        v                          v                    |    
|   +----------------+    +-------------------------+    |    
|   |                |    |                         |    |    
|   |   Add Record   |    |   Analyze Weather       |    |    
|   |   Dynamically  |    |   Trends (Daily/Overall)|    |    
|   +----------------+    +-------------------------+    |    
|        |                          |                    |    
|        |                          |                    |    
|        v                          v                    |
|   +----------------+    +-------------------------+    |                 
|   |                |    |   Compute Statistics    |    |    
|   |  Save Data to  |    |   (Max, Min, Avg Temp)  |    |    
|   |     File       |    |                         |    |    
|   +----------------+    +------------------------ +    |    
|        |                          |                    |    
|        v                          v                    |    
|   +----------------+     +------------------------+    |
|   |   Exit System  | <-- |    Detect Outliers     |    |
|   +----------------+     +------------------------+    |
+--------------------------------------------------------+
```

## 🛠 Tech Stack
- **Programming Language**: C++
- **Build System**: CMake
- **Data Storage**: CSV files
- **Data Structures**: Heap, Arrays, File Handling
- **Algorithms**: Sorting, Searching, Statistical Analysis

## 📈 Future Enhancements
- Implement a GUI for better user interaction.
- Add real-time weather data fetching from APIs.
- Enhance data visualization with interactive charts.

---
🔗 **Contributions & Feedback** are welcome! Feel free to fork the project and enhance it further. 😊
