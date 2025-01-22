### 目录

#### 枚举变量和结构体

1 枚举变量

``` c
typedef enum
{
    dusk1,
    dusk2,
    dusk3
}dusk;
//错误表述是 dusk.dusk1
//正确的用法是 dusk cur_dusk; cur_dusk=dusk1;
为什么会这样假设用盲人摸象来说的话枚举变量就相当于定义了一个有固定三种大象的大象集合  一个新的大象只可能是其中一种
这种是类别和子类别的关系

typedef struct
{
char duck_leg,
char duck_eyes,
char duck_feather,
} duck
//这种就可以这样使用 duck red_duck; red_duck.duck_leg="duck_leg"
//这种是部分与整体的关系
```