#ifdef _MSC_VER
#pragma warning( disable : 4786 )
#endif

#include "csaori.h"
#include "csaori_util.h"

/*---------------------------------------------------------
	������
---------------------------------------------------------*/
bool CSAORI::load()
{
	return true;
}

/*---------------------------------------------------------
	���
---------------------------------------------------------*/
bool CSAORI::unload()
{
	return true;
}

/*---------------------------------------------------------
	���s
---------------------------------------------------------*/
void CSAORI::exec(const CSAORIInput& in,CSAORIOutput& out)
{
	out.result_code = SAORIRESULT_OK;
	string_t a;
	for (auto& i : in.args) {
		a += L" " + i;
	}
	auto i = _wsystem(a.c_str());
	if(i!=-1)
		out.result = SAORI_FUNC::numToString(i);
	else
		out.result_code = SAORIRESULT_BAD_REQUEST;
	return;
}
