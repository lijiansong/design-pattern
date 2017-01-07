# Abstract Factory Pattern
- Abstract Factory模式通常是为了创建`一组（有多个类）`相关或者依赖的对象提供创建接口，而Factory模式是为`一类`对象提供创建接口或者延迟对象的创建到子类中实现。所以Factory模式适用于`产品种类结构单一`的场合，为一类产品提供创建的接口；而Abstract Factory模式适用于`产品种类结构多`的场合，主要用于创建一组（有多个种类）相关的产品，为它们提供创建的接口，即当具有多个抽象角色时，Abstract Factory模式便可以派上用场
- Abstract Factory模式，就好比是两个Factory模式的叠加。Abstract Factory创建的是一系列相关的对象，其中创建的实现其实就是采用的Factory模式
