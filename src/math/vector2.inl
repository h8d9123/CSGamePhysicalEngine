inline vector2& vector2::operator =(const vector2 &v)
{
    x = v.x;
    y = v.y;
    return *this;
}
inline vector2 vector2::operator +(const vector2 &v)
{
    vector2 v0(*this);
    v0.x += v.x;
    v0.y += v.y;
    return v0;
}
inline vector2 vector2::operator -(const vector2 &v)
{
    vector2 v0(*this);
    v0.x -= v.x;
    v0.y -= v.y;
    return v0;
}
inline vector2 vector2::operator *(float s)
{
    vector2 v0(*this);
    v0.x *= s;
    v0.y *= s;
    return v0;
}
inline vector2 vector2::operator /(float s)
{
    vector2 v0(*this);
    v0.x /= s;
    v0.y /= s;
    return v0;
}
inline vector2& vector2::operator +=(const vector2 &v)
{
    x += v.x;
    y += v.y;
    return *this;
}
inline vector2& vector2::operator -=(const vector2 &v)
{
    x -= v.x;
    y -= v.y;
    return *this;
}
inline vector2& vector2::operator *=(float s)
{
    x *= s;
    y *= s;
    return *this;
}
inline vector2& vector2::operator /=(float s)
{
    x /= s;
    y /= s;
    return *this;
}
inline vector2& vector2::operator !=(const vector2 &v)
{
    return ! (x == v.x && y == v.y);
}
inline vector2& vector2::operator ==(const vector2 &v)
{
    return (x == v.x && y == v.y);
}
