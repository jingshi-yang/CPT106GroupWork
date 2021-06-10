#pragma once
#include <exception>

using namespace std;

struct MaterialExistException :
	public exception
{
	const char* what() const throw() {
		return "Material is allready exist!";
	}
};

struct IllegalInputException :
	public exception
{
	const char* what() const throw() {
		return "Illegal Input!";
	}
};
struct DishnameException :
	public exception
{
	const char* what() const throw() {
		return "Dish name input illegal!";
	}
};

struct NoDishException :
	public exception
{
	const char* what() const throw() {
		return "Your chosen dish does not exist!";
	}
};

struct DishexistException :
	public exception
{
	const char* what() const throw() {
		return "Your chosen dish is already exist!";
	}
};

struct NoPermissionException :
	public exception
{
	const char* what() const throw() {
		return "You do not have permission.";
	}
};

struct QuantityIllegalException :
	public exception
{
	const char* what() const throw() {
		return "The quantity is illegal.";
	}
};

struct PriceIllegalException :
	public exception
{
	const char* what() const throw() {
		return "The price is illegal.";
	}
};

struct NoMaterialsException :
	public exception
{
	const char* what() const throw() {
		return "Material doesn't exist in inventory.";
	}
};

struct WrongUserException :
	public exception
{
	const char* what() const throw() {
		return "Wrong user id or password.";
	}
};
