# Head First Design Patterns - C++ Implementation

This repository contains C++ implementations of chapters 1 through 11 from the "Head First Design Patterns" book by Eric Freeman and Elisabeth Robson. Each chapter demonstrates a specific design pattern through a practical example, showing both problematic approaches and elegant solutions. Chapter 3 includes both a coffee shop condiment system and an I/O stream decoration example.

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
└── Chapter4_Factory/                   # Factory Patterns Implementation
    ├── abstract_factory/               # Abstract Factory Pattern
    │   ├── main.cpp                    # Abstract Factory demo
    │   ├── main                        # Compiled executable
    │   ├── ChicagoIngredientFactory.hpp # Chicago ingredient factory
    │   ├── Ingredients.hpp             # Abstract and concrete ingredients
    │   ├── NYIngredientFactory.hpp     # NY ingredient factory
    │   ├── Pizza.hpp                   # Pizza classes using factories
    │   ├── PizzaIngredientFactory.hpp  # Abstract factory interface
    │   └── PizzaStore.hpp              # Pizza stores with factories
    └── factory_method/                 # Factory Method Pattern
        ├── main.cpp                    # Factory Method demo
        ├── main                        # Compiled executable
        ├── ChicagoPizzaStore.hpp       # Chicago pizza store
        ├── NYPizzaStore.hpp            # NY pizza store
        ├── Pizza.hpp                   # Pizza classes
        └── PizzaStore.hpp              # Abstract pizza store
└── Chapter5_Singleton/                 # Singleton Pattern Implementation
    ├── main.cpp                        # Main entry point for Singleton demo
    ├── ChocolateBoiler                 # Compiled executable
    └── ChocolateBoiler.hpp             # Singleton Chocolate Boiler class
└── Chapter6_Command/                   # Command Pattern Implementation
    ├── main.cpp                        # Main entry point for Command demo
    ├── README.md                       # Chapter-specific documentation
    ├── commands/                       # Concrete command implementations
    │   ├── CeilingFanCommands.hpp
    │   ├── LightCommands.hpp
    │   ├── MacroCommand.hpp
    │   └── StereoCommands.hpp
    ├── interfaces/                     # Pattern interfaces
    │   └── Command.hpp
    ├── invoker/                        # Invoker implementation
    │   └── RemoteControl.hpp
    └── receivers/                      # Receiver classes (devices)
        ├── CeilingFan.hpp
        ├── Light.hpp
        └── Stereo.hpp
└── Chapter7_AdapterFacade/               # Adapter and Facade Patterns Implementation
    ├── Adapter/                         # Adapter Pattern
    │   ├── main.cpp                     # Main entry point for Adapter demo
    │   ├── Duck.hpp                     # Duck interface and implementation
    │   ├── Turkey.hpp                   # Turkey class
    │   └── TurkeyAdapter.hpp            # Adapter to make Turkey behave like Duck
    ├── Facade/                          # Facade Pattern
    │   ├── main.cpp                     # Main entry point for Facade demo
    │   ├── Facade                       # Compiled executable
    │   ├── Components.hpp               # Home theater components
    │   └── HomeTheaterFacade.hpp        # Facade for home theater system
    └── PrincipleOfLeastKnowledge/       # Principle of Least Knowledge Demo
        ├── BadCar.cpp                   # Violation of the principle
        └── GoodCar.cpp                  # Proper application of the principle
└── Chapter8_Template/                  # Template Method Pattern Implementation
    ├── SortHookExample/                # Sorting with hooks example
    │   └── sort.cpp                    # Sorting algorithm with customizable hooks
    └── TeaCoffeeExample/               # Caffeine beverage preparation
        ├── CaffeineBeverage.hpp        # Abstract template method class
        ├── Coffee.hpp                  # Concrete coffee implementation
        ├── main.cpp                    # Main entry point for Template demo
        ├── Tea.hpp                     # Concrete tea implementation
        └── TeaCoffeeExample            # Compiled executable
└── Chapter9_IteratorComposite/         # Iterator and Composite Patterns Implementation
    ├── Iterator/                       # Iterator Pattern
    │   ├── main.cpp                    # Main entry point for Iterator demo
    │   ├── Iterator                    # Compiled executable
    │   ├── Iterator.hpp                # Iterator interface
    │   ├── Menu.hpp                    # Menu interface and implementations
    │   └── Waitress.hpp                # Client using iterators
    └── Composite/                      # Composite Pattern
        ├── main.cpp                    # Main entry point for Composite demo
        ├── Composite                   # Compiled executable
        ├── MenuComponent.hpp           # Abstract component (leaf and composite)
        ├── MenuItem.hpp                # Leaf component (individual menu items)
        ├── Menu.hpp                    # Composite component (menus containing items/sub-menus)
        └── Waitress.hpp                # Client traversing the composite structure
└── Chapter10_State/                    # State Pattern Implementation
    ├── BadDesign/                      # Anti-pattern example
    │   └── BadGumballMachine.cpp       # Monolithic state handling
    └── StatePatternDesign/             # Proper State Pattern implementation
        ├── main.cpp                    # Main entry point for State demo
        ├── statepattern                # Compiled executable
        ├── GumballMachine.cpp          # Context class
        ├── GumballMachine.hpp          # Context header
        ├── State.hpp                   # State interface
        └── ConcreteStates/             # Concrete state implementations
            ├── HasQuarterState.hpp
            ├── NoQuarterState.hpp
            ├── SoldOutState.hpp
            ├── SoldState.hpp
            └── WinnerState.hpp
└── Chapter11_Proxy/                    # Proxy Pattern Implementation
    ├── DynamicProxy/                   # Dynamic Proxy with access control
    │   ├── main.cpp                    # Main entry point for Dynamic Proxy demo
    │   ├── handlers/                   # Proxy handlers
    │   ├── impl/                       # Real subject implementations
    │   ├── interfaces/                 # Pattern interfaces
    │   └── proxies/                    # Proxy implementations
    └── SimpleProxyLike/                # Simple Proxy examples
        ├── EnforcedProxy               # Compiled executable for enforced proxy
        ├── EnforcedProxy.cpp           # Access control proxy example
        ├── Proxymain.cpp               # Simple logging proxy example
        └── SimpleProxy                 # Compiled executable for simple proxy
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

### 🎯 Chapter 4: Factory Patterns - Pizza Store Application

**Problem**: A pizza franchise needs to create different pizza styles (NY, Chicago) with region-specific ingredients and preparation methods. Initial attempts led to tight coupling and code duplication across stores.

**Solution**: Use Factory patterns to encapsulate object creation. Factory Method lets subclasses decide what to create, while Abstract Factory provides an interface for creating families of related objects.

### 📂 Chapter4_Factory/

#### Factory Method Pattern (`factory_method/`)

**Core Components**
- **`PizzaStore.hpp`** - Abstract base class with `orderPizza()` template method
- **`NYPizzaStore.hpp`** - Creates NY-style pizzas (thin crust, marinara, reggiano)
- **`ChicagoPizzaStore.hpp`** - Creates Chicago-style pizzas (deep dish, plum tomato, mozzarella)
- **`Pizza.hpp`** - Abstract pizza with prepare/bake/cut/box methods

**Key Method**: `createPizza()` - Factory method overridden by subclasses to create specific pizzas

#### Abstract Factory Pattern (`abstract_factory/`)

**Core Components**
- **`PizzaIngredientFactory.hpp`** - Abstract factory interface for ingredient creation
- **`NYIngredientFactory.hpp`** - Creates NY ingredients (ThinCrustDough, MarinaraSauce, ReggianoCheese)
- **`ChicagoIngredientFactory.hpp`** - Creates Chicago ingredients (ThickCrustDough, PlumTomatoSauce, MozzarellaCheese)
- **`Ingredients.hpp`** - Abstract ingredient classes (Dough, Sauce, Cheese) with concrete implementations
- **`Pizza.hpp`** - Pizza classes that use ingredient factories
- **`PizzaStore.hpp`** - Pizza stores that use ingredient factories

**Key Methods**: `createDough()`, `createSauce()`, `createCheese()` - Abstract factory methods

#### Main Demos
- **Factory Method**: Each store creates complete pizzas with region-specific styles
- **Abstract Factory**: Stores use ingredient factories to create pizza components

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

### Factory Pattern Principles
1. **Depend on abstractions, not concrete classes** - Factories return abstract types
2. **Encapsulate object creation** - Hide instantiation details behind factory methods
3. **Factory Method vs Abstract Factory** - Method for single objects, Factory for object families

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

### Factory Method Demo
```bash
cd Chapter4_Factory/factory_method
g++ -std=c++17 main.cpp -o main
./main
```

### Abstract Factory Demo
```bash
cd Chapter4_Factory/abstract_factory
g++ -std=c++17 main.cpp -o main
./main
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

### Template Method Demo
```bash
cd Chapter8_Template/TeaCoffeeExample
g++ -std=c++17 main.cpp -o TeaCoffeeExample
./TeaCoffeeExample
```

### Iterator Demo
```bash
cd Chapter9_IteratorComposite/Iterator
g++ -std=c++17 main.cpp -o Iterator
./Iterator
```

### Composite Demo
```bash
cd Chapter9_IteratorComposite/Composite
g++ -std=c++17 main.cpp -o Composite
./Composite
```

### State Demo
```bash
cd Chapter10_State/StatePatternDesign
g++ -std=c++17 main.cpp GumballMachine.cpp -o statepattern
./statepattern
```

### Proxy Demos
```bash
# Simple Logging Proxy
cd Chapter11_Proxy/SimpleProxyLike
g++ -std=c++17 Proxymain.cpp -o SimpleProxy
./SimpleProxy

# Enforced Access Control Proxy
g++ -std=c++17 EnforcedProxy.cpp -o EnforcedProxy
./EnforcedProxy

# Dynamic Proxy
cd ../DynamicProxy
g++ -std=c++17 main.cpp -o DynamicProxy
./DynamicProxy
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

### Factory Patterns
- **Factory Method**: Subclasses decide which concrete classes to instantiate
- **Abstract Factory**: Interface for creating families of related objects
- **Dependency Inversion**: Depend on abstractions, not concrete classes
- **Encapsulate Creation**: Hide object creation logic behind factory interfaces
- **Regional Variations**: Easily support different product families (NY vs Chicago styles)

### Singleton Pattern
- **Single Instance Guarantee**: Ensures exactly one instance exists
- **Global Access Point**: Provides controlled access to the unique instance
- **Lazy Initialization**: Instance created only when first requested
- **Thread Safety**: Must handle concurrent access in multi-threaded environments
- **Private Constructor**: Prevents external instantiation

### Template Method Pattern
- **Algorithm Skeleton**: Defines the structure of an algorithm in a base class
- **Subclass Customization**: Allows subclasses to override specific steps
- **Inversion of Control**: Base class controls the flow, subclasses provide details
- **Hooks for Extension**: Optional methods that subclasses can override for customization
- **Code Reuse**: Common algorithm structure shared across implementations

### Iterator Pattern
- **Sequential Access**: Provides a way to access elements without exposing underlying structure
- **Polymorphic Traversal**: Same interface for iterating over different collections
- **Encapsulate Iteration**: Hide the details of traversing a collection
- **Single Responsibility**: Iterators handle traversal, collections handle storage
- **Fail-Fast Behavior**: Detect concurrent modifications during iteration

### Composite Pattern
- **Tree Structures**: Represent part-whole hierarchies uniformly
- **Recursive Composition**: Composites contain leaves and other composites
- **Transparent Operations**: Clients treat leaves and composites the same way
- **Add/Remove Dynamically**: Build complex structures at runtime
- **Shared Interface**: All components implement the same abstract interface

### State Pattern
- **State Encapsulation**: Each state becomes a separate class with its own behavior
- **Context Delegation**: Context delegates state-specific work to current state object
- **State Transitions**: States can trigger transitions to other states
- **Eliminate Conditionals**: Replace complex if-else chains with polymorphism
- **Open for Extension**: Add new states without modifying existing code

### Proxy Pattern
- **Access Control**: Control access to sensitive or expensive resources
- **Lazy Initialization**: Create expensive objects only when needed (Virtual Proxy)
- **Remote Access**: Provide local interface to remote objects
- **Logging and Monitoring**: Intercept requests for auditing or debugging
- **Transparent Substitution**: Client code works with proxy or real object identically

### 🎯 Chapter 5: Singleton Pattern - Chocolate Boiler Application

**Problem**: A chocolate factory needs a boiler that can only exist in one instance to prevent hazardous duplication. Multiple boiler instances could lead to unsafe operating conditions.

**Solution**: Use the Singleton Pattern to ensure a class has only one instance and provide a global point of access to it.

### 📂 Chapter5_Singleton/

#### Core Components

**`ChocolateBoiler.hpp`** - The Singleton Class
- Private constructor prevents direct instantiation
- Static `getInstance()` method provides global access point
- Ensures only one boiler instance exists throughout the application
- Manages boiler state (empty, filled, boiled, drained)

#### Main Demo (`main.cpp`)
- Demonstrates singleton behavior by attempting multiple instantiations
- Shows that all references point to the same instance
- Tests boiler operations (fill, boil, drain) in sequence

### 🎯 Chapter 6: Command Pattern - Remote Control Application

**Problem**: A remote control needs to execute various commands for different devices, support undo operations, and allow for macro commands. Initial implementations would require the remote to know about each device's specific methods, creating tight coupling.

**Solution**: Use the Command Pattern to encapsulate requests as objects, allowing parameterization of clients with different requests, queuing, logging, and undoable operations.

### 📂 Chapter6_Command/

#### Core Components

**`interfaces/Command.hpp`** - Command Interface
- Defines `execute()` and `undo()` methods
- Includes `NoCommand` for empty slots

**`invoker/RemoteControl.hpp`** - The Invoker
- Stores on/off commands for 7 slots
- Implements button press methods that delegate to commands
- Maintains undo command for rollback operations

**`commands/`** - Concrete Commands
- **`LightCommands.hpp`** - Light on/off commands
- **`StereoCommands.hpp`** - Stereo on/off commands with CD
- **`CeilingFanCommands.hpp`** - Ceiling fan speed control commands
- **`MacroCommand.hpp`** - Composite command for executing multiple commands

**`receivers/`** - Receiver Classes
- **`Light.hpp`** - Light device with on/off methods
- **`Stereo.hpp`** - Stereo device with on/off/CD methods
- **`CeilingFan.hpp`** - Ceiling fan with speed control

#### Main Demo (`main.cpp`)
- Sets up remote control with various device commands
- Demonstrates command execution and undo functionality
- Shows macro command usage for party mode
- Includes lambda command adapter for modern C++ flexibility

## 🎯 Chapter 7: Adapter and Facade Patterns - Duck Simulator and Home Theater

**Problem**: Need to integrate incompatible interfaces (Adapter) and simplify complex subsystem interactions (Facade).

**Solution**: Use Adapter Pattern to make incompatible classes work together, and Facade Pattern to provide a unified interface to a complex subsystem.

### 📂 Chapter7_AdapterFacade/

#### Adapter Pattern (`Adapter/`)

**Problem**: A duck simulator needs to work with turkey objects, but their interfaces are incompatible.

**Solution**: Create an adapter that translates turkey methods to duck methods.

**`Duck.hpp`** - Target interface (what the client expects)
- Defines `quack()` and `fly()` methods

**`Turkey.hpp`** - Adaptee (what we have)
- Defines `gobble()` and `fly()` methods (fly is short distance)

**`TurkeyAdapter.hpp`** - Adapter class
- Inherits from Duck, contains Turkey instance
- Translates `quack()` to `gobble()`, `fly()` to multiple short flights

#### Facade Pattern (`Facade/`)

**Problem**: A home theater system has many components (amplifier, tuner, projector, etc.) with complex interactions.

**Solution**: Provide a facade that offers simple methods like `watchMovie()` and `endMovie()`.

**`Components.hpp`** - Subsystem components
- Amplifier, Tuner, Projector, TheaterLights, Screen, PopcornPopper classes

**`HomeTheaterFacade.hpp`** - Facade class
- Contains instances of all components
- Provides high-level methods that coordinate multiple components

#### Principle of Least Knowledge (`PrincipleOfLeastKnowledge/`)

**Problem**: Objects should only communicate with their immediate friends, not reach through objects.

**`BadCar.cpp`** - Violation example
- Car directly accesses engine's carburetor methods

**`GoodCar.cpp`** - Proper application
- Car only calls engine methods, engine handles carburetor

#### Main Demos
- **Adapter**: Tests duck and turkey adapter behavior
- **Facade**: Simulates watching a movie with simple facade calls

### 🎯 Chapter 8: Template Method Pattern - Beverage and Sorting Applications

**Problem**: Algorithms often have a fixed structure with customizable steps. For example, preparing caffeine beverages (coffee/tea) follows the same process but differs in brewing and condiment addition. Sorting algorithms can have optional hooks for customization.

**Solution**: Use the Template Method Pattern to define the skeleton of an algorithm in a base class, allowing subclasses to override specific steps without changing the overall structure. Hooks provide optional extension points.

### 📂 Chapter8_Template/

#### TeaCoffeeExample/ - Caffeine Beverage Preparation

**Core Components**

**`CaffeineBeverage.hpp`** - Abstract Template Class
- Defines the template method [`prepareRecipe()`](Chapter8_Template/TeaCoffeeExample/CaffeineBeverage.hpp) with fixed algorithm steps
- Includes abstract methods [`brew()`](Chapter8_Template/TeaCoffeeExample/CaffeineBeverage.hpp) and [`addCondiments()`](Chapter8_Template/TeaCoffeeExample/CaffeineBeverage.hpp) for subclass implementation
- Provides hook method [`customerWantsCondiments()`](Chapter8_Template/TeaCoffeeExample/CaffeineBeverage.hpp) with default implementation

**`Coffee.hpp`** - Concrete Coffee Class
- Implements [`brew()`](Chapter8_Template/TeaCoffeeExample/Coffee.hpp) (dripping coffee through filter)
- Implements [`addCondiments()`](Chapter8_Template/TeaCoffeeExample/Coffee.hpp) (adding sugar and milk)
- Overrides hook to ask user if they want condiments

**`Tea.hpp`** - Concrete Tea Class
- Implements [`brew()`](Chapter8_Template/TeaCoffeeExample/Tea.hpp) (steeping tea bag)
- Implements [`addCondiments()`](Chapter8_Template/TeaCoffeeExample/Tea.hpp) (adding lemon)
- Uses default hook behavior

#### SortHookExample/ - Sorting with Hooks

**Core Components**

**`sort.cpp`** - Sorting Algorithm with Hooks
- Demonstrates template method for sorting with customizable comparison and processing hooks
- Shows how hooks allow optional customization without subclassing

#### Main Demo (`TeaCoffeeExample/main.cpp`)
- Creates coffee and tea objects
- Calls [`prepareRecipe()`](Chapter8_Template/TeaCoffeeExample/CaffeineBeverage.hpp) on each, demonstrating the template method
- Shows how the algorithm structure is fixed but steps are customized

### How to Run Template Method Demo
```bash
cd Chapter8_Template/TeaCoffeeExample
g++ -std=c++17 main.cpp -o TeaCoffeeExample
./TeaCoffeeExample
```

### 🎯 Chapter 9: Iterator and Composite Patterns - Menu System Application

**Problem**: A restaurant system needs to iterate over menu items from different menus (Iterator) and handle hierarchical menu structures where menus can contain sub-menus and items (Composite), without exposing internal details or creating tight coupling.

**Solution**: The Iterator Pattern provides a uniform way to traverse collections. The Composite Pattern allows treating individual items and groups (menus) as a single component, enabling recursive operations like printing entire menu hierarchies.

### 📂 Chapter9_IteratorComposite/

#### Iterator Pattern (`Iterator/`)

**Core Components**

**`Iterator.hpp`** - Iterator Interface
- Defines [`hasNext()`](Chapter9_IteratorComposite/Iterator/Iterator.hpp) and [`next()`](Chapter9_IteratorComposite/Iterator/Iterator.hpp) methods for traversal

**`Menu.hpp`** - Menu Interface and Implementations
- Abstract [`Menu`](Chapter9_IteratorComposite/Iterator/Menu.hpp) class with [`createIterator()`](Chapter9_IteratorComposite/Iterator/Menu.hpp) method
- Concrete menus (e.g., PancakeHouseMenu, DinerMenu) implement different storage (arrays, vectors) but provide iterators

**`Waitress.hpp`** - Client Using Iterators
- Uses [`createIterator()`](Chapter9_IteratorComposite/Iterator/Menu.hpp) to get iterators from menus
- Prints menus using a single loop via [`printMenu(Iterator*)`](Chapter9_IteratorComposite/Iterator/Waitress.hpp), demonstrating polymorphism

#### Composite Pattern (`Composite/`)

**Core Components**

**`MenuComponent.hpp`** - Abstract Component
- Defines common interface for leaves and composites, including [`print()`](Chapter9_IteratorComposite/Composite/MenuComponent.hpp), [`add()`](Chapter9_IteratorComposite/Composite/MenuComponent.hpp), [`remove()`](Chapter9_IteratorComposite/Composite/MenuComponent.hpp), and [`getChild()`](Chapter9_IteratorComposite/Composite/MenuComponent.hpp)
- Default implementations throw exceptions for unsupported operations

**`MenuItem.hpp`** - Leaf Component
- Represents individual menu items with [`print()`](Chapter9_IteratorComposite/Composite/MenuItem.hpp) method
- Implements leaf-specific behavior (e.g., no children)

**`Menu.hpp`** - Composite Component
- Represents menus that can contain items or sub-menus
- Implements [`add()`](Chapter9_IteratorComposite/Composite/Menu.hpp), [`remove()`](Chapter9_IteratorComposite/Composite/Menu.hpp), and recursive [`print()`](Chapter9_IteratorComposite/Composite/Menu.hpp) to traverse children

**`Waitress.hpp`** - Client Traversing Composites
- Calls [`print()`](Chapter9_IteratorComposite/Composite/Waitress.hpp) on the root menu component, which recursively prints the entire hierarchy

#### Main Demos
- **Iterator Demo** (`Iterator/main.cpp`): Creates menus and a [`Waitress`](Chapter9_IteratorComposite/Iterator/Waitress.hpp) client to iterate and print items without knowing menu internals.
- **Composite Demo** (`Composite/main.cpp`): Builds a hierarchical menu structure and uses [`Waitress`](Chapter9_IteratorComposite/Composite/Waitress.hpp) to print the entire tree uniformly.

### How to Run Iterator and Composite Demos
```bash
# Iterator Demo
cd Chapter9_IteratorComposite/Iterator
g++ -std=c++17 main.cpp -o Iterator
./Iterator

# Composite Demo
cd ../Composite
g++ -std=c++17 main.cpp -o Composite
./Composite
```

## 🎯 Chapter 10: State Pattern - Gumball Machine Application

**Problem**: A gumball machine has complex state-dependent behavior (insert quarter, turn crank, dispense, refill, etc.) that was initially handled with conditional statements in a single class, leading to rigid and error-prone code.

**Solution**: The State Pattern encapsulates each state as a separate class with its own behavior, allowing the context (GumballMachine) to delegate actions to the current state object. States can transition to other states, making the system extensible and maintainable.

### 📂 Chapter10_State/

#### Core Components

**`State.hpp`** - State Interface
- Defines virtual methods for all state-dependent actions: [`insertQuarter()`](Chapter10_State/StatePatternDesign/State.hpp), [`ejectQuarter()`](Chapter10_State/StatePatternDesign/State.hpp), [`turnCrank()`](Chapter10_State/StatePatternDesign/State.hpp), [`dispense()`](Chapter10_State/StatePatternDesign/State.hpp)

**`GumballMachine.hpp`** - Context Class
- Holds the current state and gumball count
- Delegates actions to the current state via [`setState()`](Chapter10_State/StatePatternDesign/GumballMachine.hpp) and [`getState()`](Chapter10_State/StatePatternDesign/GumballMachine.hpp)
- Provides actions like [`insertQuarter()`](Chapter10_State/StatePatternDesign/GumballMachine.hpp), [`turnCrank()`](Chapter10_State/StatePatternDesign/GumballMachine.hpp), [`refill()`](Chapter10_State/StatePatternDesign/GumballMachine.hpp)

**Concrete States** (`ConcreteStates/`)
- **`NoQuarterState.hpp`**: Handles quarter insertion, rejects other actions
- **`HasQuarterState.hpp`**: Accepts crank turning, transitions to SoldState or WinnerState (10% chance)
- **`SoldState.hpp`**: Dispenses gumball, transitions to NoQuarterState or SoldOutState
- **`SoldOutState.hpp`**: Rejects all actions except refill
- **`WinnerState.hpp`**: Dispenses two gumballs for winner, then transitions appropriately

#### Main Demo
- **State Demo** (`StatePatternDesign/main.cpp`): Simulates gumball machine usage, testing winner state (10% chance), and refill functionality.

### 🎯 Chapter 11: Proxy Pattern - Internet Access and Person Profile Applications

**Problem**: Need to control access to expensive or sensitive resources, add logging/monitoring, or provide virtual access to remote objects without changing client code.

**Solution**: Use the Proxy Pattern to provide a surrogate or placeholder for another object to control access to it. The proxy acts as an intermediary, intercepting requests and potentially adding behavior before delegating to the real object.

### 📂 Chapter11_Proxy/

#### Simple Proxy Examples (`SimpleProxyLike/`)

**Simple Logging Proxy** (`Proxymain.cpp`)
- **`InternetService`** - Subject interface defining the contract
- **`RealInternet`** - Real subject that performs actual work (simulated internet connection)
- **`ProxyInternet`** - Proxy that adds logging before delegating to real internet
- Demonstrates basic interception and delegation

**Enforced Access Control Proxy** (`EnforcedProxy.cpp`)
- **`Internet`** - Subject interface
- **`RealInternet`** - Real subject with private constructor (enforced singleton-like access)
- **`ProxyInternet`** - Proxy that controls access, blocks banned sites, and manages real internet lifecycle
- Shows how proxy can enforce security policies and control object creation

#### Dynamic Proxy with Access Control (`DynamicProxy/`)

**Core Components**
- **`PersonBean`** - Subject interface for person profiles
- **`PersonBeanImpl`** - Real subject implementation
- **`ProxyFactory`** - Factory creating different proxy types based on access level
- **Owner Proxy**: Allows self-modification but prevents self-rating
- **Non-Owner Proxy**: Allows rating others but prevents modifying their profile

**Key Features**
- Dynamic proxy creation based on user permissions
- Fine-grained access control (read/write restrictions)
- Transparent interception of method calls
- Separation of concerns between real object and access logic

#### Main Demos
- **Simple Proxy**: Demonstrates logging and basic interception
- **Enforced Proxy**: Shows access control and resource protection
- **Dynamic Proxy**: Illustrates role-based access control for social features

### How to Run Proxy Demos
```bash
# Simple Logging Proxy
cd Chapter11_Proxy/SimpleProxyLike
g++ -std=c++17 Proxymain.cpp -o SimpleProxy
./SimpleProxy

# Enforced Access Control Proxy
g++ -std=c++17 EnforcedProxy.cpp -o EnforcedProxy
./EnforcedProxy

# Dynamic Proxy
cd ../DynamicProxy
g++ -std=c++17 main.cpp -o DynamicProxy
./DynamicProxy
```

### How to Run State Demo
```bash
cd Chapter10_State/StatePatternDesign
g++ -std=c++17 main.cpp GumballMachine.cpp -o statepattern
./statepattern
```

- **Language**: C++17
- **Memory Management**: Uses smart pointers (`std::unique_ptr`) for automatic memory management
- **Compilation**: Requires C++17 support for `std::make_unique`
- **Architecture**: Each chapter is self-contained with its own main function
- **Pattern Implementation**: Faithful to the book's examples with modern C++ idioms

This implementation serves as both a learning tool and a reference for applying these fundamental design patterns in C++ applications.