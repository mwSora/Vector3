#include <iostream>

struct Vector3 {
	Vector3() { 
		this->x = 0, this->y = 0, this->z = 0;
	};

	template <typename vectorNumber>
	Vector3(vectorNumber x = 0, vectorNumber y = 0, vectorNumber z = 0)
	{
		this->x = static_cast<float>(x), this->y = static_cast<float>(y), this->z = static_cast<float>(z);
	}

	void reset()
	{
		this->x = 0, this->y = 0, this->z = 0;
	}

	friend std::ostream& operator << (std::ostream& os, const Vector3& vec)
	{
		os << "Vector3(" << vec.x << ", " << vec.y << ", " << vec.z << ")";
		return os;
	}

	template <typename vectorNumber>
	void operator + (vectorNumber nb)
	{
		this->x += static_cast<float>(nb), this->y += static_cast<float>(nb), this->z += static_cast<float>(nb);
	}

	template <typename vectorNumber>
	void operator - (vectorNumber nb)
	{
		this->x -= static_cast<float>(nb), this->y -= static_cast<float>(nb), this->z -= static_cast<float>(nb);
	}

	template <typename vectorNumber>
	void operator * (vectorNumber nb)
	{
		this->x *= static_cast<float>(nb), this->y *= static_cast<float>(nb), this->z *= static_cast<float>(nb);
	}

	template <typename vectorNumber>
	void operator / (vectorNumber nb)
	{
		this->x /= static_cast<float>(nb), this->y /= static_cast<float>(nb), this->z /= static_cast<float>(nb);
	}

	Vector3 operator + (Vector3& secondVector)
	{
		Vector3 retVector;
		retVector.x = this->x + secondVector.x, retVector.y = this->y + secondVector.y, retVector.z = this->z + secondVector.z;
		return retVector;
	}

	Vector3 operator - (Vector3& secondVector)
	{
		Vector3 retVector;
		retVector.x = this->x - secondVector.x, retVector.y = this->y - secondVector.y, retVector.z = this->z - secondVector.z;
		return retVector;
	}

	Vector3 operator * (Vector3& secondVector)
	{
		Vector3 retVector;
		retVector.x = this->x * secondVector.x, retVector.y = this->y * secondVector.y, retVector.z = this->z * secondVector.z;
		return retVector;
	}

	Vector3 operator / (Vector3& secondVector)
	{
		Vector3 retVector;
		retVector.x = this->x / secondVector.x, retVector.y = this->y / secondVector.y, retVector.z = this->z / secondVector.z;
		return retVector;
	}

	float x, y, z;
};

int main()
{
	Vector3 vec(100.f, 200.f, 500.58f);
	Vector3 secondVec(0, 0, 2);

	Vector3 newVec = vec + secondVec; 
	std::cout << newVec << std::endl; // Vector3(100, 200, 502.58)

	newVec / 2;
	std::cout << newVec << std::endl; // Vector3(50, 100, 251.29)

	newVec * 10;
	std::cout << newVec << std::endl; // Vector3(500, 1000, 2512.9)

	newVec.x += 100;
	std::cout << newVec << std::endl; // Vector3(600, 1000, 2512.9)

	newVec.reset();
	std::cout << newVec << std::endl; // Vector3(0, 0, 0)

	newVec.x = 100, newVec.y = 100;
	newVec * 2.5;
	std::cout << newVec << std::endl; // Vector3(250, 250, 0)
}