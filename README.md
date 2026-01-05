# Head First Design Patterns - C++ Implementation

This repository contains C++ implementations of the first three chapters from the "Head First Design Patterns" book by Eric Freeman and Elisabeth Robson. Each chapter demonstrates a specific design pattern through a practical example, showing both problematic approaches and elegant solutions. Chapter 3 includes both a coffee shop condiment system and an I/O stream decoration example.

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
└── Chapter3_Decorator/                 # Decorator Pattern Implementation
    ├── main.cpp                        # Main entry point for Decorator demo
    ├── StarbuzzCoffee                  # Compiled executable
    ├── bad_designs/                    # Anti-pattern examples
    │   └── RigidBeverage.cpp           # Class explosion violation
    ├── component/                      # Pattern components
    │   ├── Beverage.hpp                # Abstract component
    │   └── CondimentDecorator.hpp      # Abstract decorator
    ├── concrete_beverages/             # Concrete components
    │   ├── DarkRoast.hpp
    │   └── Espresso.hpp
    └── decorators/                     # Concrete decorators
        ├── Mocha.hpp
        ├── Soy.hpp
        └── Whip.hpp
└── Chapter3_IO_Decorator/              # I/O Decorator Pattern Example
    ├── main.cpp                        # Main entry point for I/O Decorator demo
    ├── DecoratorIO                     # Compiled executable
    ├── concrete_streams/               # Concrete input stream
    │   └── StringInputStream.hpp       # String-based input stream
    ├── decorators/                     # Concrete decorators
    │   └── LowerCaseInputStream.hpp    # Lowercase conversion decorator
    └── interfaces/                     # Pattern interfaces
        ├── FilterInputStream.hpp       # Abstract decorator base
        └── InputStream.hpp             # Abstract component
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

### 🎯 Chapter 3: Decorator Pattern - Starbuzz Coffee Application

**Problem**: A coffee shop needs to add various condiments to beverages. Initial attempts using inheritance or modifying the base class led to a class explosion and rigid code that couldn't handle multiple combinations or new condiments easily.

**Solution**: Use the Decorator Pattern to wrap beverages with condiment decorators, allowing unlimited combinations without subclassing.

### 📂 Chapter3_Decorator/

#### Core Components

**`component/`** - Pattern Abstractions
- **`Beverage.hpp`** - Abstract component class with size support
  - Defines the interface for all beverages and decorators
  - Includes size enum (TALL, GRANDE, VENTI) that affects pricing
- **`CondimentDecorator.hpp`** - Abstract decorator base
  - Inherits from Beverage (IS-A relationship)
  - Forces decorators to implement getDescription()

**`concrete_beverages/`** - Concrete Components
- **`Espresso.hpp`** - Basic espresso beverage
- **`DarkRoast.hpp`** - Dark roast coffee beverage

**`decorators/`** - Concrete Decorators
- **`Mocha.hpp`** - Adds mocha syrup, price varies by size
- **`Soy.hpp`** - Adds soy milk, price varies by size
- **`Whip.hpp`** - Adds whipped cream, price varies by size

#### Anti-Pattern Example (`bad_designs/RigidBeverage.cpp`)

**Class Explosion Violation**
- Base Beverage class contains boolean flags for every condiment
- Adding new condiments requires modifying the base class
- No support for multiple instances of same condiment (e.g., double mocha)
- Violates "Open for extension, closed for modification"
- Leads to rigid, hard-to-maintain code

#### Main Demo (`main.cpp`)
- Orders simple espresso (no decorators)
- Orders complex dark roast with double mocha and whip
- Demonstrates size-based pricing (venti affects condiment costs)
- Shows how decorators wrap beverages dynamically

### 📂 Chapter3_IO_Decorator/ - I/O Stream Decorator Example

This folder contains an additional Decorator Pattern implementation using I/O streams, demonstrating how the pattern can be applied to different domains.

#### Core Components

**`interfaces/`** - Pattern Interfaces
- **`InputStream.hpp`** - Abstract component for input streams
- **`FilterInputStream.hpp`** - Abstract decorator base that wraps input streams

**`concrete_streams/StringInputStream.hpp`** - Concrete Component
- Reads characters from a string sequentially

**`decorators/LowerCaseInputStream.hpp`** - Concrete Decorator
- Wraps an input stream and converts all characters to lowercase

#### Main Demo (`main.cpp`)
- Creates a string input stream with mixed-case text
- Wraps it with a lowercase decorator
- Reads and displays the decorated output

### Strategy Pattern Principles
1. **Encapsulate what varies** - Flying and quacking behaviors vary, so encapsulate them
2. **Favor composition over inheritance** - Ducks get their behavior via composition
3. **Program to interfaces, not implementations** - Duck class works with behavior interfaces

### Observer Pattern Principles
1. **Strive for loosely coupled designs** - Subject and observers are loosely coupled
2. **Don't depend on concrete classes** - Subject works with Observer interface
3. **Open for extension, closed for modification** - Add new observers without changing subject

### Decorator Pattern Principles
1. **Open for extension, closed for modification** - Add new decorators without changing existing code
2. **Favor composition over inheritance** - Decorators wrap components via composition
3. **Classes should be open for extension but closed for modification** - Core principle of the pattern

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

### Decorator Pattern Demo
```bash
cd Chapter3_Decorator
g++ -std=c++17 main.cpp -o StarbuzzCoffee
./StarbuzzCoffee
```

### I/O Decorator Demo
```bash
cd Chapter3_IO_Decorator
g++ -std=c++17 main.cpp -o DecoratorIO
./DecoratorIO
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

cd ../../Chapter3_Decorator/bad_designs
g++ -std=c++17 RigidBeverage.cpp -o rigid_beverage
./rigid_beverage
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

### Decorator Pattern
- **Dynamic Composition**: Add responsibilities dynamically at runtime
- **Wrapper Pattern**: Decorators wrap components, adding behavior transparently
- **Size Matters**: Decorators can be aware of component state (like beverage size)
- **Unlimited Layers**: Stack multiple decorators for complex combinations
- **Domain Agnostic**: Pattern applies to beverages, I/O streams, and other domains

## 🔧 Technical Details

- **Language**: C++17
- **Memory Management**: Uses smart pointers (`std::unique_ptr`) for automatic memory management
- **Compilation**: Requires C++17 support for `std::make_unique`
- **Architecture**: Each chapter is self-contained with its own main function
- **Pattern Implementation**: Faithful to the book's examples with modern C++ idioms

This implementation serves as both a learning tool and a reference for applying these fundamental design patterns in C++ applications.