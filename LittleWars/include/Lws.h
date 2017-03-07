#pragma once
#include <cmath>
namespace LWs {
	template<typename _Ty>

	class vector
	{
	public:
		explicit vector() {}
		vector(_Ty X, _Ty Y) :x_(X), y_(Y)
		{}
		vector(const vector<_Ty> &axis) :x_(axis.x_), y_(axis.y_) {}

		template<typename _Ty_>
		vector(const vector<_Ty_> &axis) : x_(_Ty(axis.x_)), y_(_Ty(axis.y_)) {}

		virtual ~vector() {}

		vector<_Ty> operator+=(const vector<_Ty>& axis) {
			x_ += axis.x_;
			y_ += axis.y_;
			return *this;
		}
		vector<_Ty> operator-=(const vector<_Ty>& axis) {
			x_ -= axis.x_;
			y_ -= axis.y_;
			return *this;
		}
		vector<_Ty> operator+(const vector<_Ty>& axis)const {
			return vector<_Ty>(this->x_ + axis.x_, this->y_ + axis.y_);
		}
		vector<_Ty> operator-(const vector<_Ty>& axis)const {
			return vector<_Ty>(this->x_ - axis.x_, this->y_ - axis.y_);
		}
		vector<_Ty> operator*(const int integer)const {
			return _multiply(integer);
		}
		vector<_Ty> operator*(const double real)const {
			return _multiply(real);
		}
		vector<_Ty> operator*(const float real)const {
			return _multiply(real);
		}
		vector<_Ty> operator=(const vector<_Ty>& axis) {
			x_ = axis.x_;
			y_ = axis.y_;
			return *this;
		}
		bool operator==(const vector<_Ty> &axis)const {
			return (this->x_ == axis.x_ && this->y_ == axis.y_);
		}
		bool operator!=(const vector<_Ty> &axis)const {
			return !(*this == axis);
		}
		_Ty Square()const { return x_*x_ + y_*y_; }
		double GetArgument()const {
			return atan2(y_, x_);
		}
		_Ty x_, y_;
	private:
		template<class _RealNumber>
		vector<_Ty> _multiply(const _RealNumber k)const {
			return vector<_Ty>(this->x_ * k, this->y_ * k);
		}
	};
}