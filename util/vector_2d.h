#pragma once

namespace strawx {

	template <class T>
	struct Vector2D
	{
		T x, y;

		Vector2D() = default;
		Vector2D(T value) : Vector2D{ value, value } { }
		Vector2D(T x, T y) : x{ x }, y{ y } { }

		Vector2D operator+(const Vector2D& other)
		{
			return Vector2D{ this->x + other.x, this->y + other.y };
		}

		void operator+=(const Vector2D& other)
		{
			this->x += other.x;
			this->y += other.y;
		}
		
		Vector2D operator-(const Vector2D& other)
		{
			return Vector2D{ this->x - other.x, this->y - other.y };
		}

		void operator-=(const Vector2D& other)
		{
			this->x -= other.x;
			this->y -= other.y;
		}

	};

	using Vector2F = Vector2D<float>;
	using Vector2I = Vector2D<int>;

}