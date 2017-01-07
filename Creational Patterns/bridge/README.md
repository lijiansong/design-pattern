# Bridge Pattern
Bridge模式将抽象和实现分开，独立地实现。Bridge模式是OO开发中经常用到的设计模式之一，
使用组合（委托）的方式将抽象和实现彻底地解耦，这样的好处是抽象和实现可以分别独立地变化，系统的耦合性也得到了很好的降低。以下情形比较适合使用Bridge模式：
- 如果不希望在抽象和它的实现部分之间有一个固定的绑定关系，也就是继承关系；如果我们打破了这种固定的绑定关系以后，就可以方便的在抽象部分切换不同的实现部分；
- 如果希望类的抽象以及它的实现都应该可以通过生成子类的方法加以扩充；如果不使用桥接模式，使用继承去实现时，在抽象类中添加一个方法，则在对应的实现类中也需要做对应的改动，这种实现不符合松耦合的要求；
- 如果要求对一个抽象的实现部分的修改对客户不产生影响，即客户的代码不需要重新编译；
- 如果想对客户完全隐藏抽象的实现部分；
- 如果一个对象有多个变化因素的时候，通过抽象这些变化因素，将依赖具体实现，修改为依赖抽象；
- 如果某个变化因素在多个对象中共享时，可以抽象出这个变化因素，然后实现这些不同的变化因素。

桥接模式使得抽象和实现进行了分离，抽象不用依赖于实现，让抽象和实现部分各自修改起来都很方便，使用组合（即Abstraction类中包含了Implementor）的方式，降低了耦合度，同时也有助于分层，从而产生更好的结构化系统。
使用Bridge模式和使用带来问题方式的解决方案的根本区别在于是`通过继承还是通过组合`的方式去实现一个功能需求。