#ifndef GAUSSIAN_FILTER_H_
#define GAUSSIAN_FILTER_H_
#include <systemc>
using namespace sc_core;

#ifndef NATIVE_SYSTEMC
#include <cynw_p2p.h>
#endif


class Matrix_Mult: public sc_module
{
public:
	sc_in_clk i_clk;
	sc_in < bool >  i_rst;
	sc_out < bool > PE_rdy;
#ifndef NATIVE_SYSTEMC
	cynw_p2p< sc_dt::sc_uint<33> >::in i_data;
	cynw_p2p< sc_dt::sc_biguint<64> >::out o_result;
#else
	sc_fifo_in< sc_dt::sc_uint<33> > i_data;
	sc_fifo_out< sc_dt::sc_biguint<64> > o_result;
#endif

	SC_HAS_PROCESS( Matrix_Mult );
	Matrix_Mult( sc_module_name n );
	~Matrix_Mult();
private:
	void do_mult();

	sc_dt::sc_uint<33> data_wire;
	sc_dt::sc_biguint<64> o_data_wire;
	sc_dt::sc_int<8> W[4][4];
	sc_dt::sc_int<8> IA[4][4];
	sc_dt::sc_int<16> OA[4][4];
	sc_dt::sc_uint<1> mode;
	sc_dt::sc_int<16> Tmp;

};
#endif
