#ifndef CONNECTION_POOL_H
#define CONNECTION_POOL_H
#include <node.h>
using namespace node;
using namespace v8;
#include "../../core/otlPool.h"
class ConnctionPool :public ObjectWrap
{
	public:
		ConnctionPool(void);
		virtual ~ConnctionPool(void);
		static void Init(Handle<Object> target);
		static Handle<Value> New(const Arguments& args);
		static Handle<Value> GetConnn(const Arguments& args);//��ȡ����
		static Handle<Value> ReleaseConn(const Arguments& args);//�ͷ�����
	
	public:
		static otlPool* p_otl_pool;//oracle���ӳ�
		static Persistent<FunctionTemplate> constructorTemplate;
	
	private:
		static void EIO_Get_Connect(uv_work_t* req);
		static void EIO_AfterConnect(uv_work_t* req, int status); //�ص�����
};


#endif
