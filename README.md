# Design Patterns

Design patterns are reusable solutions to commonly occurring software design problems.  
They help make code more **flexible, maintainable, reusable, and loosely coupled**.

## Creational Design Patterns

| Design Pattern | Problem It Solves |
|---|---|
| **Singleton** | Solves the problem of controlling object creation when exactly one instance of a class should exist. It also provides a single, globally accessible point to that instance. |
| **Prototype** | Solves the problem of creating expensive or complex objects repeatedly. Instead of constructing an object from scratch, a new object is created by cloning an existing one. |
| **Builder** | Solves the problem of constructing complex objects that have many optional parameters or multiple construction steps. It separates the construction process from the final object's representation. |
| **Simple Factory** *(Idiom — Not GoF)* | Solves the problem of scattering object-creation logic throughout the client code. A factory centralizes the creation logic and returns the appropriate object based on input. |
| **Factory Method** | Solves the problem of tightly coupling client code to concrete classes during object creation. It defines a creation method and allows subclasses to decide which concrete object to create. |
| **Abstract Factory** | Solves the problem of creating families of related objects while keeping the client independent of their concrete implementations. It ensures that related objects are created consistently. |

## Structural Design Patterns

| Design Pattern | Problem It Solves |
|---|---|
| **Adapter** | Solves the problem of incompatible interfaces. It acts as a bridge between two classes so existing code can work with a new or incompatible interface without modifying the original classes. |
| **Bridge** | Solves the problem of having a class hierarchy grow in multiple dimensions, such as different shapes and different rendering methods. It separates abstraction from implementation so both can evolve independently. |
| **Composite** | Solves the problem of treating individual objects and groups of objects differently. It organizes objects into a tree structure and allows clients to treat both individual objects and compositions uniformly. |
| **Decorator** | Solves the problem of adding responsibilities or features to an object dynamically without modifying its original class. Multiple decorators can also be combined to add different behaviors. |
| **Facade** | Solves the problem of exposing a complicated subsystem directly to clients. It provides a simple, high-level interface that hides unnecessary implementation details. |
| **Proxy** | Solves the problem of controlling access to another object. A proxy can provide lazy loading, access control, caching, logging, remote access, or other additional behavior. |

## Behavioral Design Patterns

| Design Pattern | Problem It Solves |
|---|---|
| **Chain of Responsibility** | Solves the problem of tightly coupling a request sender to a specific receiver. The request is passed through a chain of handlers until one of them can process it. |
| **Command** | Solves the problem of directly coupling an object that requests an operation with the object that performs it. It encapsulates a request as an object, enabling undo, queuing, logging, and delayed execution. |
| **Iterator** | Solves the problem of traversing a collection without exposing its internal representation. It provides a standard interface for sequentially accessing elements. |
| **Mediator** | Solves the problem of complex many-to-many communication between objects. A mediator centralizes communication so objects do not need to directly depend on one another. |
| **Memento** | Solves the problem of saving and restoring an object's previous state without exposing its internal implementation. It is commonly used for undo/rollback functionality. |
| **Observer** | Solves the problem of keeping multiple objects synchronized when another object's state changes. The subject automatically notifies all registered observers about changes. |
| **State** | Solves the problem of having large conditional statements that change an object's behavior based on its current state. Each state is represented as a separate class containing state-specific behavior. |
| **Strategy** | Solves the problem of having multiple interchangeable algorithms implemented through complex conditional logic. It encapsulates each algorithm separately and allows the algorithm to be changed at runtime. |
| **Template Method** | Solves the problem of duplicated algorithm structures across subclasses. It defines the overall algorithm in a base class while allowing subclasses to customize specific steps. |
| **Visitor** | Solves the problem of frequently adding new operations to an existing object structure. It separates operations from the objects on which they operate, avoiding modifications to every element class. |
| **Interpreter** | Solves the problem of interpreting a simple language or grammar. It represents grammar rules as objects and provides a mechanism for evaluating expressions according to those rules. |
