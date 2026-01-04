# Head First Design Patterns - C++ Implementation

This repository contains C++ implementations of the first two chapters from the "Head First Design Patterns" book by Eric Freeman and Elisabeth Robson. Each chapter demonstrates a specific design pattern through a practical example, showing both problematic approaches and elegant solutions.

## 📁 Project Structure Overview

```
head-first-design-patterns/
├── README.md                           # This documentation file
├── Chapter2_Observer/                  # Observer Pattern Implementation
│   ├── main.cpp                        # Main entry point for Observer demo
│   ├── WeatherORama                    # Compiled executable
│   ├── bad_designs/                    # Anti-pattern examples
│   │   └── WrongWeatherData.cpp        # Tight coupling violation
│   ├── displays/                       # Observer implementations
│   │   ├── CurrentConditionsDisplay.hpp
│   │   ├── ForecastDisplay.hpp
│   │   └── StatisticsDisplay.hpp
│   ├── interfaces/                     # Pattern interfaces
│   │   ├── DisplayElement.hpp
│   │   ├── Observer.hpp
│   │   └── Subject.hpp
│   └── weather/                        # Subject implementation
│       └── WeatherData.hpp
└── SimUDuck_Chapter_1_StrategyPattern/ # Strategy Pattern Implementation
    ├── main.cpp                        # Main entry point for Strategy demo
    ├── SimUDuck                        # Compiled executable
    ├── Duck.hpp                        # Abstract Duck base class
    ├── bad_designs/                    # Anti-pattern examples
    │   ├── InheritanceTrap.cpp         # Inheritance abuse
    │   └── InterfaceTrap.cpp           # Interface misuse
    ├── behaviors/                      # Strategy interfaces & implementations
    │   ├── FlyBehavior.hpp             # Fly strategy interface
    │   ├── FlyNoWay.hpp                # Concrete fly strategy
    │   ├── FlyWithWings.hpp            # Concrete fly strategy
    │   ├── MuteQuack.hpp               # Concrete quack strategy
    │   ├── Quack.hpp                   # Concrete quack strategy
    │   ├── QuackBehavior.hpp           # Quack strategy interface
    │   └── Squeak.hpp                  # Concrete quack strategy
    └── ducks/                          # Concrete Duck implementations
        ├── MallardDuck.hpp
        └── RubberDuck.hpp
```

## 🎯 Chapter 1: Strategy Pattern - SimUDuck Application

**Problem**: A duck simulation game needs different duck types with varying flying and quacking behaviors. Initial attempts using inheritance and interfaces led to code duplication and inflexibility.

**Solution**: Use the Strategy Pattern to encapsulate behaviors as separate objects that can be swapped at runtime.

### 📂 SimUDuck_Chapter_1_StrategyPattern/

#### Core Components

**`Duck.hpp`** - Abstract base class
- Defines the interface for all ducks
- Contains composition relationships with behavior interfaces
- Provides setters for dynamic behavior changes at runtime

**`behaviors/`** - Strategy Implementations
- **`FlyBehavior.hpp`** - Interface for flying strategies
- **`QuackBehavior.hpp`** - Interface for quacking strategies
- **Concrete Strategies**:
  - `FlyWithWings.hpp` - Normal flying behavior
  - `FlyNoWay.hpp` - No flying behavior (for rubber ducks, injured ducks)
  - `Quack.hpp` - Normal quacking
  - `MuteQuack.hpp` - Silent behavior
  - `Squeak.hpp` - Squeaking sound (rubber duck)

**`ducks/`** - Concrete Duck Classes
- **`MallardDuck.hpp`** - Real duck that flies and quacks
- **`RubberDuck.hpp`** - Toy duck that squeaks and doesn't fly

#### Anti-Pattern Examples (`bad_designs/`)

**`InheritanceTrap.cpp`** - The Inheritance Abuse Problem
- Shows how forcing all ducks to inherit flying behavior causes rubber ducks to "fly"
- Demonstrates violation of "Program to an interface, not an implementation"
- Rubber ducks inherit unwanted flying capability

**`InterfaceTrap.cpp`** - The Interface Misuse Problem
- Shows how using interfaces without composition leads to code duplication
- Multiple duck classes reimplement the same flying logic
- No way to share common behavior implementations

#### Main Demo (`main.cpp`)
- Tests MallardDuck (flies with wings, quacks normally)
- Tests RubberDuck (doesn't fly, squeaks)
- Demonstrates runtime behavior change (Mallard gets injured, loses flying ability)

### 🎯 Chapter 2: Observer Pattern - Weather-O-Rama Application

**Problem**: A weather monitoring system needs to update multiple displays when weather data changes. Initial implementation had tight coupling between the weather station and display devices.

**Solution**: Use the Observer Pattern to create a loose coupling between subjects (weather data) and observers (displays).

### 📂 Chapter2_Observer/

#### Core Components

**`interfaces/`** - Pattern Interfaces
- **`Subject.hpp`** - Interface for objects being observed (defines register/remove/notify methods)
- **`Observer.hpp`** - Interface for observing objects (defines update method)
- **`DisplayElement.hpp`** - Interface for displayable objects (defines display method)

**`weather/WeatherData.hpp`** - The Subject (Concrete Subject)
- Implements Subject interface
- Maintains list of registered observers
- Stores weather measurements (temperature, humidity, pressure)
- Implements both PUSH and PULL models (currently using PULL)
- PUSH model: Subject sends data directly to observers
- PULL model: Observers pull data from subject when notified

**`displays/`** - Observer Implementations (Concrete Observers)
- **`CurrentConditionsDisplay.hpp`** - Shows current temperature and humidity
- **`StatisticsDisplay.hpp`** - Shows average, max, and min temperatures
- **`ForecastDisplay.hpp`** - Shows weather forecast based on pressure changes

#### Anti-Pattern Example (`bad_designs/WrongWeatherData.cpp`)

**Tight Coupling Violation**
- WeatherData directly instantiates and manages display objects
- No common interface between displays
- Adding new displays requires modifying WeatherData class
- Violates "Depend on abstractions, not concrete classes"
- Makes the system rigid and hard to extend

#### Main Demo (`main.cpp`)
- Creates WeatherData subject
- Registers three display observers
- Simulates three weather measurement updates
- Shows how all displays automatically update when data changes

## 🏗️ Design Principles Demonstrated

### Strategy Pattern Principles
1. **Encapsulate what varies** - Flying and quacking behaviors vary, so encapsulate them
2. **Favor composition over inheritance** - Ducks get their behavior via composition
3. **Program to interfaces, not implementations** - Duck class works with behavior interfaces

### Observer Pattern Principles
1. **Strive for loosely coupled designs** - Subject and observers are loosely coupled
2. **Don't depend on concrete classes** - Subject works with Observer interface
3. **Open for extension, closed for modification** - Add new observers without changing subject

## 🚀 How to Run

### Strategy Pattern Demo
```bash
cd SimUDuck_Chapter_1_StrategyPattern
g++ -std=c++17 main.cpp -o SimUDuck
./SimUDuck
```

### Observer Pattern Demo
```bash
cd Chapter2_Observer
g++ -std=c++17 main.cpp -o WeatherORama
./WeatherORama
```

### Bad Design Examples
```bash
cd SimUDuck_Chapter_1_StrategyPattern/bad_designs
g++ -std=c++17 InheritanceTrap.cpp -o inheritance_trap
./inheritance_trap

g++ -std=c++17 InterfaceTrap.cpp -o interface_trap
./interface_trap

cd ../../Chapter2_Observer/bad_designs
g++ -std=c++17 WrongWeatherData.cpp -o wrong_weather
./wrong_weather
```

## 📚 Key Learning Points

### Strategy Pattern
- **Composition > Inheritance**: Use composition to include behaviors rather than inheriting them
- **Runtime Flexibility**: Change behavior at runtime by swapping strategy objects
- **Code Reuse**: Share behavior implementations across different classes
- **Interface Segregation**: Each behavior has its own interface

### Observer Pattern
- **Push vs Pull Models**: Push sends data directly, Pull lets observers fetch what they need
- **Registration Management**: Subjects maintain observer lists and handle registration/deregistration
- **Automatic Updates**: Observers automatically notified when subject state changes
- **Decoupling**: Subject doesn't need to know concrete observer types

## 🔧 Technical Details

- **Language**: C++17
- **Memory Management**: Uses smart pointers (`std::unique_ptr`) for automatic memory management
- **Compilation**: Requires C++17 support for `std::make_unique`
- **Architecture**: Each chapter is self-contained with its own main function
- **Pattern Implementation**: Faithful to the book's examples with modern C++ idioms

This implementation serves as both a learning tool and a reference for applying these fundamental design patterns in C++ applications.