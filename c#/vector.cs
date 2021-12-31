//badger
using System;
using System.Drawing;

public interface i_vector{
	public static int x;
	public static int y;
};
public struct vector2 : i_vector, IEquatable<vector2>, ICloneable, IDisposable{
	private static bool check(vector2 v1, vector2 v2) { return (v1.x == v2.x && v1.y == v2.y); }

	public int x;
	public int y;
	public vector2(int a1) { x = a1; y = a1; }
	public vector2(vector2 v2) { x = v2.x; y = v2.y; }
	public vector2(int x1, int y1) { x = x1; y = y1; }
	public vector2(Size s) { x = s.Width; y = s.Height; }
	public static implicit operator vector2(int a1) { return new vector2() { x = a1, y = a1 }; }
	public static explicit operator vector2(Size a1) => new vector2(a1);
	public static bool operator ==(vector2 v1, vector2 v2) { return check(v1, v2); }
	public static bool operator !=(vector2 v1, vector2 v2) { return !check(v1, v2); }
	public static vector2 operator ++(vector2 v1) { vector2 b1 = new vector2(v1); b1.x++; b1.y++; return b1; }
	public bool Equals(vector2 a1) { return check(this, a1); }
	public object Clone() { return new vector2(this); }
	public override string ToString() { return base.ToString() + ": [ x: " + x.ToString() + ", y: " + y.ToString() + "]"; }
	public void Dispose() { this = new vector2(0); }
	public Point to_location() { return new Point(x, y); }
	public Size to_size() { return new Size(x, y); }
};
public struct vector3 : i_vector, IEquatable<vector3>, ICloneable
{
	private static bool check(vector3 v1, vector3 v2) { return (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z); }

	public int x;
	public int y;
	public int z;
	public vector3(int a1) { x = a1; y = a1; z = a1; }
	public vector3(vector3 v3) { x = v3.x; y = v3.y; z = v3.z; }
	public vector3(vector2 v2, int z1) { x = v2.x; y = v2.y; z = z1; }
	public vector3(int x1, int y1, int z1) { x = x1; y = y1; z = z1; }
	public static implicit operator vector3(int a1) { return new vector3(a1); }
	public static explicit operator vector3(vector2 a1) => new vector3(a1, 0);
	public static bool operator ==(vector3 v1, vector3 v2) { return check(v1, v2); }
	public static bool operator !=(vector3 v1, vector3 v2) { return !check(v1, v2); }
	public bool Equals(vector3 a1) { return check(this, a1); }
	public object Clone() { return new vector3(this); }
};
public struct vector4 : i_vector, IEquatable<vector4>, ICloneable{
	private static bool check(vector4 v1, vector4 v2) { return (v1.x == v2.x && v1.y == v2.y && v1.w == v2.w && v1.h == v2.h); }

	public int x;
	public int y;
	public int w;
	public int h;
	public vector4(int a1) { x = a1; y = a1; w = a1; h = a1; }
	public vector4(vector4 v4) { x = v4.x; y = v4.y; w = v4.w; h = v4.h; }
	public vector4(vector2 v2, int w1, int h1) { x = v2.x; y = v2.y; w = w1; h = h1; }
	public vector4(int x1, int y1, int w1, int h1) { x = x1; y = y1; w = w1; h = h1; }
	public static implicit operator vector4(int a1) { return new vector4() { x = a1, y = a1, w = a1, h = a1 }; }
	public static explicit operator vector4(vector2 a1) => new vector4(a1, 0, 0);
	public static bool operator ==(vector4 v1, vector4 v2) { return check(v1, v2); }
	public static bool operator !=(vector4 v1, vector4 v2) { return !check(v1, v2); }
	public bool Equals(vector4 a1) { return check(this, a1); }
	public object Clone() { return new vector4(this); }
};