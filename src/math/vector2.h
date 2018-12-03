#pragma once
/**
 * a vector with 2 dimension
 */
class vector2
{
public:
    vector2();
    vector2(float x, float y);
    vector2(const vector2& v);

    inline vector2& operator =(const vector2 &v);
    inline vector2 operator +(const vector2 &v);
    inline vector2 operator -(const vector2 &v);
    inline vector2 operator *(float s);
    inline vector2 operator /(float s);
    inline vector2& operator +=(const vector2 &v);
    inline vector2& operator -=(const vector2 &v);
    inline vector2& operator *=(float s);
    inline vector2& operator /=(float s);
    inline vector2& operator !=(const vector2 &v);
    inline vector2& operator ==(const vector2 &v);
    
    ~vector2();

private:
    float x;
    float y;
};
#incluce "math/vector2.inl"
