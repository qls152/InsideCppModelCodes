
static vtable* *__VTT_1B[1+n+m] = {
    B的主虚表指针，(primary pointer);
    sub-VTT[n]; // (假设存在子VTT，不论是secondary VTT还是虚VTT)
    B secondary虚表指针[m];// 针对于B的所有基类，且该基类满足secondary虚表指针产生的条件
};

B(B* this, vtable** ctorvtbls) {
    for (base A : B) {
        // 针对于每个类B的基类
        if(has_ctorvtbl(A)) {
            // 如果基类A有一个构造虚表，也即类A的基类中有虚基类
            // 那么A初始化过程如下所示
            A((A*)this, ctorvtbls + 子VTT索引(A)); // 也即需要找到类A的子VTT的入口，并将其传入A的构造函数中
        } else {
            A((A*)this);
        }
    }

    // 开始初始化虚指针
    this->vptr = cotorvtbls + 0; // 初始化主虚表指针

    for (每个子对象A : B) {
      if (has_ctorvtbl(A)) {
        ((A*)this)->vptr = ctorvtbls + 1 + n + A的secondary虚表指针索引; 
        // 其中n为子VTT的个数
      } else {
        ((A*)this)->vptr = &(A在B中的虚表的地址)
      }
    }

    // 初始化类B的其他成员
}