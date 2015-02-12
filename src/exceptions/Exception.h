#pragma once
#include "../SharedHeaders.h"

#define EXCEPTION_INFO __FUNCTION__,__LINE__

namespace sx {
	class Exception : public std::exception {
	public:
		Exception(std::string func, uint32_t line, std::string reason) : func(func), line(line), reason(reason) {}
		~Exception() = default;

		virtual std::string msg() const {
			return func + "(" + std::to_string(line) + "): " + what() + " " + reason;
		};

	protected:
		std::string func;
		uint32_t line;
		std::string reason;
	};

	class WeakPtrException : public Exception {
	public:
		WeakPtrException(std::string func, uint32_t line) : Exception(func, line, "") {}
		~WeakPtrException() = default;

		const char* what() const override {
			return "WeakPtrException";
		}
	};

	class InvalidKeyException : public Exception {
	public:
		InvalidKeyException(std::string func, uint32_t line, std::string key)
			: Exception(func, line, "key: " + key) {
		}
		~InvalidKeyException() = default;

		const char* what() const override {
			return "InvalidKeyException";
		}
	};

	class LogicException : public Exception {
	public:
		LogicException(std::string func, uint32_t line, std::string reason)
			: Exception(func, line, reason) {
		}
		~LogicException() = default;

		const char* what() const override {
			return "LogicException";
		}
	};
}