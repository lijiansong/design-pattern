# Flyweight Pattern
flyweight即轻量级的意思，flyweight模式即享元模式。在具体实现时，Flyweight模式中有一个类似Factory模式的对象构造工厂FlyweightFactory，当客户程序员（Client）需要一个对象时候就会向FlyweightFactory发出请求对象的消息GetFlyweight（）消息，FlyweightFactory拥有一个管理、存储对象的“仓库”（或者叫对象池，vector实现），GetFlyweight（）消息会遍历对象池中的对象，如果已经存在则直接返回给Client，否则创建一个新的对象返回给Client。当然可能也有不想被共享的对象（例如结构图中的UnshareConcreteFlyweight）。

享元模式可以避免大量非常相似对象的开销。在程序设计时，有时需要生成大量细粒度的类实例来表示数据。如果能发现这些实例数据除了几个参数外基本都是相同的，使用享元模式就可以大幅度地减少对象的数量。
享元模式适用于以下场景：
- 一个应用程序使用了大量的对象；
- 完全由于使用大量的对象，造成很大的存储开销；
- 对象的大多数状态都可变为外部状态；
- 如果删除对象的外部状态，那么可以用相对较少的共享对象取代很多组对象。
