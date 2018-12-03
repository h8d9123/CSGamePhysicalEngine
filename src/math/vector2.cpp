vector2::vector2():x(0.0f), y(0.0f){};
vector2::vector2(float x, float y):x(x), y(y){};
vector2::vector2(const vector2 v)
{
    x = v.x;
    y = v.y;
}
