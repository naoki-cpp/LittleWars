#pragma once
#include <cmath>
namespace lws {
	template<typename _Ty>
	class Vector
	{
	public:
		explicit Vector() {}
		Vector(_Ty X, _Ty Y) :x_(X), y_(Y)
		{}
		Vector(const Vector<_Ty> &vector) :x_(vector.x_), y_(vector.y_) {}

		template<typename _Ty_>
		Vector(const Vector<_Ty_> &vector) : x_(_Ty(vector.x_)), y_(_Ty(vector.y_)) {}

		virtual ~Vector() {}

		Vector<_Ty> operator+=(const Vector<_Ty>& vector) {
			x_ += vector.x_;
			y_ += vector.y_;
			return *this;
		}
		Vector<_Ty> operator-=(const Vector<_Ty>& vector) {
			x_ -= vector.x_;
			y_ -= vector.y_;
			return *this;
		}
		Vector<_Ty> operator+(const Vector<_Ty>& vector)const {
			return lws::Vector<_Ty>(this->x_ + vector.x_, this->y_ + vector.y_);
		}
		Vector<_Ty> operator-(const Vector<_Ty>& vector)const {
			return lws::Vector<_Ty>(this->x_ - vector.x_, this->y_ - vector.y_);
		}
		Vector<_Ty> operator*(const int integer)const {
			return _multiply(integer);
		}
		Vector<_Ty> operator*(const double real)const {
			return _multiply(real);
		}
		Vector<_Ty> operator*(const float real)const {
			return _multiply(real);
		}
		Vector<_Ty> operator=(const Vector<_Ty>& vector) {
			x_ = vector.x_;
			y_ = vector.y_;
			return *this;
		}
		bool operator==(const Vector<_Ty> &vector)const {
			return (this->x_ == vector.x_ && this->y_ == vector.y_);
		}
		bool operator!=(const Vector<_Ty> &vector)const {
			return !(*this == vector);
		}
		_Ty Square()const { return x_*x_ + y_*y_; }
		double GetArgument()const {
			return atan2(y_, x_);
		}
		_Ty x_, y_;
	private:
		template<class _RealNumber>
		Vector<_Ty> _multiply(const _RealNumber k)const {
			return Vector<_Ty>(this->x_ * k, this->y_ * k);
		}
	};
}