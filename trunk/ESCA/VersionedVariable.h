#ifndef VERSIONED_VARIABLE_H
#define VERSIONED_VARIABLE_H

#include <sstream>

#include "Variable.h"

class VersionedVariable : public Variable
{
	public:
		VersionedVariable() : Variable() {}
		VersionedVariable(const VersionedVariable &vv) : Variable(vv) {version = vv.version;}
		VersionedVariable(std::string t, std::string n, EMetaType mt, int ver) : Variable(t, n, mt), version(ver) {}

		inline int Version() const { return version; }
		inline std::string VersionedName() const { std::stringstream ss; ss << name << "!" << version; return ss.str(); }

		//friend bool operator ==(const VersionedVariable &lhs, const VersionedVariable &rhs); 
		//friend bool operator <(const VersionedVariable &lhs, const VersionedVariable &rhs); 
	private:
		int version;
};

bool operator ==(const VersionedVariable &lhs, const VersionedVariable &rhs); 
bool operator <(const VersionedVariable &lhs, const VersionedVariable &rhs); 
#endif
