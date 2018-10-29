#ifndef CONVERTOR_H
#define CONVERTOR_H

#ifdef __cplusplus 
extern "C" {
#endif 

typedef  enum _conv_res_t {
	convERR_OK,

} conv_res_t;


conv_res_t convert_int_to_str(int, char*);



#ifdef __cplusplus
}
#endif

#endif // CONVERTOR_H