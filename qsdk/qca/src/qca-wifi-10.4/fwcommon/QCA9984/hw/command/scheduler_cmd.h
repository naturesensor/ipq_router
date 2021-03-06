// Copyright (c) 2014 Qualcomm Atheros, Inc.  All rights reserved.
// $ATH_LICENSE_HW_HDR_C$
//
// DO NOT EDIT!  This file is automatically generated
//               These definitions are tied to a particular hardware layout


#ifndef _SCHEDULER_CMD_H_
#define _SCHEDULER_CMD_H_
#if !defined(__ASSEMBLER__)
#endif

// ################ START SUMMARY #################
//
//	Dword	Fields
//	0	schedule_id[15:0], sifs_response_cmd[16], txop_time_ctrl[17], ndp_frame[18], ndp_frame_bw[20:19], enable_bw_check[21], fes_control_mode[23:22], ibss_beacon_frame[24], max_schedule_retries[28:25], stall_schedule_enable[29], reserved_0[30], clear_cv_info[31]
//	1	scr_timer0_restart[0], scr_timer1_restart[1], scr_timer0_restart_after[2], scr_timer1_restart_after[3], sifs_burst_continuation[4], burst_continuation_ifs_time[5], force_requeue_to_filter[6], reserved_1a[7], reserved_1b[9:8], start_time_reference[12:10], end_time_reference[15:13], sch_max_txop_time[29:16], pause_on_filter[30], filter_on_bw_failure[31]
//	2	scheduler_tlv_ptr[31:0]
//	3	schedule_lifetime_exp[31:0]
//	4	schedule_start_time[31:0]
//	5	peer_entry_ptr0[31:0]
//	6	peer_entry_ptr1[31:0]
//	7	peer_entry_ptr2[31:0]
//
// ################ END SUMMARY #################

#define NUM_OF_DWORDS_SCHEDULER_CMD 8

struct scheduler_cmd {
    volatile uint32_t schedule_id                     : 16, //[15:0]
                      sifs_response_cmd               :  1, //[16]
                      txop_time_ctrl                  :  1, //[17]
                      ndp_frame                       :  1, //[18]
                      ndp_frame_bw                    :  2, //[20:19]
                      enable_bw_check                 :  1, //[21]
                      fes_control_mode                :  2, //[23:22]
                      ibss_beacon_frame               :  1, //[24]
                      max_schedule_retries            :  4, //[28:25]
                      stall_schedule_enable           :  1, //[29]
                      reserved_0                      :  1, //[30]
                      clear_cv_info                   :  1; //[31]
    volatile uint32_t scr_timer0_restart              :  1, //[0]
                      scr_timer1_restart              :  1, //[1]
                      scr_timer0_restart_after        :  1, //[2]
                      scr_timer1_restart_after        :  1, //[3]
                      sifs_burst_continuation         :  1, //[4]
                      burst_continuation_ifs_time     :  1, //[5]
                      force_requeue_to_filter         :  1, //[6]
                      reserved_1a                     :  1, //[7]
                      reserved_1b                     :  2, //[9:8]
                      start_time_reference            :  3, //[12:10]
                      end_time_reference              :  3, //[15:13]
                      sch_max_txop_time               : 14, //[29:16]
                      pause_on_filter                 :  1, //[30]
                      filter_on_bw_failure            :  1; //[31]
    volatile uint32_t scheduler_tlv_ptr               : 32; //[31:0]
    volatile uint32_t schedule_lifetime_exp           : 32; //[31:0]
    volatile uint32_t schedule_start_time             : 32; //[31:0]
    volatile uint32_t peer_entry_ptr0                 : 32; //[31:0]
    volatile uint32_t peer_entry_ptr1                 : 32; //[31:0]
    volatile uint32_t peer_entry_ptr2                 : 32; //[31:0]
};

/*

schedule_id
			
			Schedule command identifier
			
			
			
			A field that HW copies over into the scheduling status
			report, so that SW can determine to which scheduler command
			the status report belongs.
			
			This schedule ID is also reported in the PPDU status.   
			  
			
			<legal all>

sifs_response_cmd
			
			SIFS response command
			
			
			
			0: No action: transmission of the command is initialized
			by expiration of the BO engine, or SIFS burst continuation.
			
			
			
			1: Transmission of the frame related to this command
			should appear in the medium SIFS time after the current
			ongoing transmission of an self-generated response frame
			(ACK or BA) finishes.
			
			
			
			This setting is only used by SW when it has received a
			Qboost, PS-POLL of U-APSD trigger, and want the response
			data frame to go out at SIFS time after the acknowledgement 
			(ACK or BA) of the trigger frame has gone out.
			
			
			
			<legal all>

txop_time_ctrl
			
			<enum 0  Basic >  The schedules will take the
			sch_max_TXOP_time value, compare that with other TXOP
			boundaries (like TBTT), and select the smallest value. This
			is then put into field max_TXOP_time in the PDG_FES_SETUP
			TLV, or compared with FES_total_transmit time in case of SW
			transmit mode
			
			
			
			<enum 1  Start_after_bo_or_ongoing >  If this scheduling
			command is called directly after the expiration of a backoff
			engine, start the TXOP timer at the start of frame
			transmission with the value indicated in field:
			sch_max_txop_time. if this scheduling command is part of a
			series of SIFS burst commands and not the first one called
			after BO expiration, the TXOP timer is NOT initialized with
			this value. It is assumed that the TXOP timer has already
			been initialized the by the previous commands.
			
			The scheduler will insert the current TXOP timer value
			(or smaller other TXOP boundary values), in field
			max_TXOP_time in the PDG_FES_SETUP TLV.
			
			<legal all>

ndp_frame
			
			When set, the scheduling command contains an NDP frame.
			This can only be done using the SW transmit mode. <legal
			all>

ndp_frame_bw
			
			<enum 0  20MHz_ndp> NDP transmitted at 20 Mhz
			
			<enum 1  40MHz_ndp> NDP transmitted at 40 Mhz
			
			<enum 2  80MHz_ndp> NDP transmitted at 80 Mhz
			
			<enum 3  160MHz_ndp> NDP transmitted at 160 Mhz
			
			
			
			
			
			<legal 0-3>

enable_bw_check
			
			Enable the BW check for CBF. The pause_on_filter knob
			will force scheduler to PAUSE else the command will be
			filtered. If pause_on_filter is not set, next command will
			be at random backoff, even if part of same BURST.
			
			<legal all>

fes_control_mode
			
			<enum 0  SW_transmit_mode>  No HW generated TLVs
			
			
			
			<enum 1 PDG_transmit_mode> PDG  is activated to generate
			TLVs
			
			
			
			Note: Final Bandwidth selection is always performed by
			TX PCU.
			
			
			
			<legal 0-1>

ibss_beacon_frame
			
			When set, this scheduling command refers to an IBSS
			beacon frame.
			
			
			
			In IBSS, beacon transmission is initiated at TBTT. The
			beacon will go out after a regular Backoff period, or not at
			all if a beacon from another STA belonging to the same IBSS
			is received. During this period, all backoff engines for
			regular data transmissions are paused. They get re-enabled
			when either the other beacon is received, or this beacon
			frame got transmitted (and this configuration bit was set).
			
			 <legal all>

max_schedule_retries
			
			The maximum number of times this scheduler command can
			be tried if execution did not result in a successful FES
			transmission.
			
			
			
			For example: No ACK or BA frame was received at all
			after PPDU transmission. Or no CTS frame was received after
			transmitting an RTS.
			
			If for this transmission, no response frames are
			expected, this field will be ignored.<legal all>

stall_schedule_enable
			
			This is the global control for SW to specify PAUSE for a
			non-BURST command.<legal all>

reserved_0
			
			Reserved: Generator should set to 0 and consumer shall
			ignore.  <legal 0>

clear_cv_info
			
			0: No action (Not supported)
			
			1: Clear all the internal scheduler CV tracking info.
			The result is that for a next beamformed transmission
			(including MU-MIMO) the scheduler will discard the CV info
			that might already have been in the PHY, and will force a
			new CV parameters read from memory. <legal 1>

scr_timer0_restart
			
			Scheduler command ring (scr) timer 0 restart
			
			0: No action
			
			1: Restart the internal scheduler command ring timer0 at
			first time this scheduling command is evaluated by HW.
			<legal all>

scr_timer1_restart
			
			Scheduler command ring (scr) timer 1 restart
			
			0: No action
			
			1: Restart the internal scheduler command ring timer1 at
			first time this scheduling command is evaluated by HW.
			<legal all>

scr_timer0_restart_after
			
			Scheduler command ring timer (scr) 0 restart after
			
			0: No action
			
			1: Restart the internal scheduler command ring timer0
			after this scheduling command has finished successfully (=>
			Ack was received, or no response expected) <legal all>

scr_timer1_restart_after
			
			Scheduler command ring timer (scr) 1 restart after
			
			0: No action
			
			1: Restart the internal scheduler command ring timer1
			after this scheduling command has finished successfully (=>
			Ack was received, or no response expected) <legal all>

sifs_burst_continuation
			
			SIFS burst continuation
			
			0: No action
			
			1: The next scheduling command needs to start at SIFS
			time after finishing the frame transmissions in this
			command. This allows for SIFS based bursting
			
			
			
			<legal all>

burst_continuation_ifs_time
			
			
			
			
			<enum 0  SIFS> : Interframe space between 2 consecutive
			scheduling commands is SIFS.
			
			<enum 1  PIFS> : Interframe space between 2 consecutive
			scheduling commands is PIFS. This mode can be used in
			combination with Qboost, where it is not known up front if
			there will be any return data coming when a qboost trigger
			frame has been sent.
			
			<legal all>

force_requeue_to_filter
			
			If set, HWSCH will treat re-queue condition as same as
			pause. 

reserved_1a
			
			Reserved: Generator should set to 0, consumer shall
			ignore
			
			<legal 0>

reserved_1b
			
			Reserved: Generator should set to 0, consumer shall
			ignore
			
			<legal 0>

start_time_reference
			
			Indicates the reference clock to be used for checking
			the scheduling start time
			
			<enum 0 TSF1>
			
			<enum 1 TSF2>
			
			<enum 2 WB_Timer>
			
			<enum 3 queue_timer0> Internal scheduler command queue
			timer 0
			
			<enum 4 queue_timer1> Internal scheduler command queue
			timer 1
			
			<legal 0-4>

end_time_reference
			
			Indicates the reference clock to be used for checking
			the lifetime expiration time of the command.
			
			<enum 0 TSF1>
			
			<enum 1 TSF2>
			
			<enum 2 WB_Timer>
			
			<enum 3 queue_timer0> Internal scheduler command queue
			timer 0
			
			<enum 4 queue_timer1> Internal scheduler command queue
			timer 1
			
			<legal 0-4>

sch_max_txop_time
			
			The maximum amount of TXOP time (in 4 us units).
			
			
			
			When field TXOP_time_ctrl is set to Basic:
			
			Scheduler will compare this value with other TXOP
			limiting inputs, for example how much time there is to TBTT.
			This is then the final available TXOP time, which is passed
			on to PDG in PDG transmit mode, or is used to compare
			against the FES_total_transmit time in case of SW transmit
			mode
			
			
			
			When field TXOP_time_ctrl is set to
			Start_after_bo_or_ongoing:
			
			If this is the first scheduling command called after BO
			expiration, the  scheduler initializes an internal TXOP
			timer with this value. The contents of that timer is
			compared with the other TXOP boundary timers (like TBTT),
			and passed on to the PDG in PDG transmit mode, or is used to
			compare against the FES_total_transmit time in case of SW
			transmit mode
			
			If this is this scheduling command is NOT the first
			first scheduling command called after BO expiration, this
			value is ignored. The scheduler will take the time value
			that is remaining in TXOP timer (initialized in earlier
			commands), and use that as the remaining max TXOP time. 
			This TXOP time is compared with the other TXOP boundaries,
			and the smallest one is selected, and passed on to PDG, or
			compared with FES_total_transmit time in case of SW transmit
			mode
			
			
			
			
			
			<legal all>

pause_on_filter
			
			This is the global control for SW to specify PAUSE
			during a BURST sequence.

filter_on_bw_failure
			
			Filter this scheduler command if the required bandwidth
			for this scheduling command was higher than the available
			bandwidth.  If this bit is not set then this results in a
			quiet collision and new backoff without incrementing the
			transmit try count.  If this bit is set then the scheduling
			command is filtered. 

scheduler_tlv_ptr
			
			The address location for the transmit TLVs.
			
			These TLVs get read/interpreted by the scheduler and
			when applicable pushed down the transmit chain to the other
			transmit modules. <legal all>

schedule_lifetime_exp
			
			Scheduling command lifetime expiration time.
			
			A value of zero: Command never expires
			
			A non-zero value: the Timestamp at which the scheduler
			command expires. 
			
			Note that End_Time_reference indicates what the
			reference timer is.HW assumes the timer wraps around at 32
			bits, and checks that the actual reference time is within
			the programmed time and this value minus 2^31. If not, the
			lifetime is assumed to be expired.
			
			
			
			SCH and PDG will ensure that any transmission will not
			go over this lifetime. SCH will take this Lifetime boundary
			into account when calculating the remaining TXOP time.
			
			
			
			 <legal all>

schedule_start_time
			
			Scheduling command start time.
			
			A value of zero: Start time check is not enabled
			
			A non-zero value: the Timestamp before which the
			scheduler command may not be executed. The TX scheduler
			module will pause till this time is reached. Note that
			Start_Time_reference indicates what the reference timer is.
			
			HW assumes the timer wraps around at 32 bits, and checks
			that  the actual reference time is within the programmed
			time (schedule_start_time) and this value plus 2^31. If not,
			start time has not been reached yet. <legal all>

peer_entry_ptr0
			
			Pointer to the peer entry for user 0
			
			This pointer is used by the scheduler to initially check
			if the STA is in power save mode or not. (this check can be
			enabled with sta_pwr_state_chk_en field)
			
			
			
			<legal all>

peer_entry_ptr1
			
			This entry is NOT valid when equal to 0.
			
			
			
			Pointer to the peer entry for user 1
			
			This pointer is used by the scheduler to initially check
			if the STA is in power save mode or not. (this check can be
			enabled with sta_pwr_state_chk_en field)
			
			<legal all>

peer_entry_ptr2
			
			This entry is NOT valid when equal to 0.
			
			
			
			Pointer to the peer entry for user 2
			
			This pointer is used by the scheduler to initially check
			if the STA is in power save mode or not. (this check can be
			enabled with sta_pwr_state_chk_en field)
			
			
			
			
			
			<legal all>
*/


/* Description		SCHEDULER_CMD_0_SCHEDULE_ID
			
			Schedule command identifier
			
			
			
			A field that HW copies over into the scheduling status
			report, so that SW can determine to which scheduler command
			the status report belongs.
			
			This schedule ID is also reported in the PPDU status.   
			  
			
			<legal all>
*/
#define SCHEDULER_CMD_0_SCHEDULE_ID_OFFSET                           0x00000000
#define SCHEDULER_CMD_0_SCHEDULE_ID_LSB                              0
#define SCHEDULER_CMD_0_SCHEDULE_ID_MASK                             0x0000ffff

/* Description		SCHEDULER_CMD_0_SIFS_RESPONSE_CMD
			
			SIFS response command
			
			
			
			0: No action: transmission of the command is initialized
			by expiration of the BO engine, or SIFS burst continuation.
			
			
			
			1: Transmission of the frame related to this command
			should appear in the medium SIFS time after the current
			ongoing transmission of an self-generated response frame
			(ACK or BA) finishes.
			
			
			
			This setting is only used by SW when it has received a
			Qboost, PS-POLL of U-APSD trigger, and want the response
			data frame to go out at SIFS time after the acknowledgement 
			(ACK or BA) of the trigger frame has gone out.
			
			
			
			<legal all>
*/
#define SCHEDULER_CMD_0_SIFS_RESPONSE_CMD_OFFSET                     0x00000000
#define SCHEDULER_CMD_0_SIFS_RESPONSE_CMD_LSB                        16
#define SCHEDULER_CMD_0_SIFS_RESPONSE_CMD_MASK                       0x00010000

/* Description		SCHEDULER_CMD_0_TXOP_TIME_CTRL
			
			<enum 0  Basic >  The schedules will take the
			sch_max_TXOP_time value, compare that with other TXOP
			boundaries (like TBTT), and select the smallest value. This
			is then put into field max_TXOP_time in the PDG_FES_SETUP
			TLV, or compared with FES_total_transmit time in case of SW
			transmit mode
			
			
			
			<enum 1  Start_after_bo_or_ongoing >  If this scheduling
			command is called directly after the expiration of a backoff
			engine, start the TXOP timer at the start of frame
			transmission with the value indicated in field:
			sch_max_txop_time. if this scheduling command is part of a
			series of SIFS burst commands and not the first one called
			after BO expiration, the TXOP timer is NOT initialized with
			this value. It is assumed that the TXOP timer has already
			been initialized the by the previous commands.
			
			The scheduler will insert the current TXOP timer value
			(or smaller other TXOP boundary values), in field
			max_TXOP_time in the PDG_FES_SETUP TLV.
			
			<legal all>
*/
#define SCHEDULER_CMD_0_TXOP_TIME_CTRL_OFFSET                        0x00000000
#define SCHEDULER_CMD_0_TXOP_TIME_CTRL_LSB                           17
#define SCHEDULER_CMD_0_TXOP_TIME_CTRL_MASK                          0x00020000

/* Description		SCHEDULER_CMD_0_NDP_FRAME
			
			When set, the scheduling command contains an NDP frame.
			This can only be done using the SW transmit mode. <legal
			all>
*/
#define SCHEDULER_CMD_0_NDP_FRAME_OFFSET                             0x00000000
#define SCHEDULER_CMD_0_NDP_FRAME_LSB                                18
#define SCHEDULER_CMD_0_NDP_FRAME_MASK                               0x00040000

/* Description		SCHEDULER_CMD_0_NDP_FRAME_BW
			
			<enum 0  20MHz_ndp> NDP transmitted at 20 Mhz
			
			<enum 1  40MHz_ndp> NDP transmitted at 40 Mhz
			
			<enum 2  80MHz_ndp> NDP transmitted at 80 Mhz
			
			<enum 3  160MHz_ndp> NDP transmitted at 160 Mhz
			
			
			
			
			
			<legal 0-3>
*/
#define SCHEDULER_CMD_0_NDP_FRAME_BW_OFFSET                          0x00000000
#define SCHEDULER_CMD_0_NDP_FRAME_BW_LSB                             19
#define SCHEDULER_CMD_0_NDP_FRAME_BW_MASK                            0x00180000

/* Description		SCHEDULER_CMD_0_ENABLE_BW_CHECK
			
			Enable the BW check for CBF. The pause_on_filter knob
			will force scheduler to PAUSE else the command will be
			filtered. If pause_on_filter is not set, next command will
			be at random backoff, even if part of same BURST.
			
			<legal all>
*/
#define SCHEDULER_CMD_0_ENABLE_BW_CHECK_OFFSET                       0x00000000
#define SCHEDULER_CMD_0_ENABLE_BW_CHECK_LSB                          21
#define SCHEDULER_CMD_0_ENABLE_BW_CHECK_MASK                         0x00200000

/* Description		SCHEDULER_CMD_0_FES_CONTROL_MODE
			
			<enum 0  SW_transmit_mode>  No HW generated TLVs
			
			
			
			<enum 1 PDG_transmit_mode> PDG  is activated to generate
			TLVs
			
			
			
			Note: Final Bandwidth selection is always performed by
			TX PCU.
			
			
			
			<legal 0-1>
*/
#define SCHEDULER_CMD_0_FES_CONTROL_MODE_OFFSET                      0x00000000
#define SCHEDULER_CMD_0_FES_CONTROL_MODE_LSB                         22
#define SCHEDULER_CMD_0_FES_CONTROL_MODE_MASK                        0x00c00000

/* Description		SCHEDULER_CMD_0_IBSS_BEACON_FRAME
			
			When set, this scheduling command refers to an IBSS
			beacon frame.
			
			
			
			In IBSS, beacon transmission is initiated at TBTT. The
			beacon will go out after a regular Backoff period, or not at
			all if a beacon from another STA belonging to the same IBSS
			is received. During this period, all backoff engines for
			regular data transmissions are paused. They get re-enabled
			when either the other beacon is received, or this beacon
			frame got transmitted (and this configuration bit was set).
			
			 <legal all>
*/
#define SCHEDULER_CMD_0_IBSS_BEACON_FRAME_OFFSET                     0x00000000
#define SCHEDULER_CMD_0_IBSS_BEACON_FRAME_LSB                        24
#define SCHEDULER_CMD_0_IBSS_BEACON_FRAME_MASK                       0x01000000

/* Description		SCHEDULER_CMD_0_MAX_SCHEDULE_RETRIES
			
			The maximum number of times this scheduler command can
			be tried if execution did not result in a successful FES
			transmission.
			
			
			
			For example: No ACK or BA frame was received at all
			after PPDU transmission. Or no CTS frame was received after
			transmitting an RTS.
			
			If for this transmission, no response frames are
			expected, this field will be ignored.<legal all>
*/
#define SCHEDULER_CMD_0_MAX_SCHEDULE_RETRIES_OFFSET                  0x00000000
#define SCHEDULER_CMD_0_MAX_SCHEDULE_RETRIES_LSB                     25
#define SCHEDULER_CMD_0_MAX_SCHEDULE_RETRIES_MASK                    0x1e000000

/* Description		SCHEDULER_CMD_0_STALL_SCHEDULE_ENABLE
			
			This is the global control for SW to specify PAUSE for a
			non-BURST command.<legal all>
*/
#define SCHEDULER_CMD_0_STALL_SCHEDULE_ENABLE_OFFSET                 0x00000000
#define SCHEDULER_CMD_0_STALL_SCHEDULE_ENABLE_LSB                    29
#define SCHEDULER_CMD_0_STALL_SCHEDULE_ENABLE_MASK                   0x20000000

/* Description		SCHEDULER_CMD_0_RESERVED_0
			
			Reserved: Generator should set to 0 and consumer shall
			ignore.  <legal 0>
*/
#define SCHEDULER_CMD_0_RESERVED_0_OFFSET                            0x00000000
#define SCHEDULER_CMD_0_RESERVED_0_LSB                               30
#define SCHEDULER_CMD_0_RESERVED_0_MASK                              0x40000000

/* Description		SCHEDULER_CMD_0_CLEAR_CV_INFO
			
			0: No action (Not supported)
			
			1: Clear all the internal scheduler CV tracking info.
			The result is that for a next beamformed transmission
			(including MU-MIMO) the scheduler will discard the CV info
			that might already have been in the PHY, and will force a
			new CV parameters read from memory. <legal 1>
*/
#define SCHEDULER_CMD_0_CLEAR_CV_INFO_OFFSET                         0x00000000
#define SCHEDULER_CMD_0_CLEAR_CV_INFO_LSB                            31
#define SCHEDULER_CMD_0_CLEAR_CV_INFO_MASK                           0x80000000

/* Description		SCHEDULER_CMD_1_SCR_TIMER0_RESTART
			
			Scheduler command ring (scr) timer 0 restart
			
			0: No action
			
			1: Restart the internal scheduler command ring timer0 at
			first time this scheduling command is evaluated by HW.
			<legal all>
*/
#define SCHEDULER_CMD_1_SCR_TIMER0_RESTART_OFFSET                    0x00000004
#define SCHEDULER_CMD_1_SCR_TIMER0_RESTART_LSB                       0
#define SCHEDULER_CMD_1_SCR_TIMER0_RESTART_MASK                      0x00000001

/* Description		SCHEDULER_CMD_1_SCR_TIMER1_RESTART
			
			Scheduler command ring (scr) timer 1 restart
			
			0: No action
			
			1: Restart the internal scheduler command ring timer1 at
			first time this scheduling command is evaluated by HW.
			<legal all>
*/
#define SCHEDULER_CMD_1_SCR_TIMER1_RESTART_OFFSET                    0x00000004
#define SCHEDULER_CMD_1_SCR_TIMER1_RESTART_LSB                       1
#define SCHEDULER_CMD_1_SCR_TIMER1_RESTART_MASK                      0x00000002

/* Description		SCHEDULER_CMD_1_SCR_TIMER0_RESTART_AFTER
			
			Scheduler command ring timer (scr) 0 restart after
			
			0: No action
			
			1: Restart the internal scheduler command ring timer0
			after this scheduling command has finished successfully (=>
			Ack was received, or no response expected) <legal all>
*/
#define SCHEDULER_CMD_1_SCR_TIMER0_RESTART_AFTER_OFFSET              0x00000004
#define SCHEDULER_CMD_1_SCR_TIMER0_RESTART_AFTER_LSB                 2
#define SCHEDULER_CMD_1_SCR_TIMER0_RESTART_AFTER_MASK                0x00000004

/* Description		SCHEDULER_CMD_1_SCR_TIMER1_RESTART_AFTER
			
			Scheduler command ring timer (scr) 1 restart after
			
			0: No action
			
			1: Restart the internal scheduler command ring timer1
			after this scheduling command has finished successfully (=>
			Ack was received, or no response expected) <legal all>
*/
#define SCHEDULER_CMD_1_SCR_TIMER1_RESTART_AFTER_OFFSET              0x00000004
#define SCHEDULER_CMD_1_SCR_TIMER1_RESTART_AFTER_LSB                 3
#define SCHEDULER_CMD_1_SCR_TIMER1_RESTART_AFTER_MASK                0x00000008

/* Description		SCHEDULER_CMD_1_SIFS_BURST_CONTINUATION
			
			SIFS burst continuation
			
			0: No action
			
			1: The next scheduling command needs to start at SIFS
			time after finishing the frame transmissions in this
			command. This allows for SIFS based bursting
			
			
			
			<legal all>
*/
#define SCHEDULER_CMD_1_SIFS_BURST_CONTINUATION_OFFSET               0x00000004
#define SCHEDULER_CMD_1_SIFS_BURST_CONTINUATION_LSB                  4
#define SCHEDULER_CMD_1_SIFS_BURST_CONTINUATION_MASK                 0x00000010

/* Description		SCHEDULER_CMD_1_BURST_CONTINUATION_IFS_TIME
			
			
			
			
			<enum 0  SIFS> : Interframe space between 2 consecutive
			scheduling commands is SIFS.
			
			<enum 1  PIFS> : Interframe space between 2 consecutive
			scheduling commands is PIFS. This mode can be used in
			combination with Qboost, where it is not known up front if
			there will be any return data coming when a qboost trigger
			frame has been sent.
			
			<legal all>
*/
#define SCHEDULER_CMD_1_BURST_CONTINUATION_IFS_TIME_OFFSET           0x00000004
#define SCHEDULER_CMD_1_BURST_CONTINUATION_IFS_TIME_LSB              5
#define SCHEDULER_CMD_1_BURST_CONTINUATION_IFS_TIME_MASK             0x00000020

/* Description		SCHEDULER_CMD_1_FORCE_REQUEUE_TO_FILTER
			
			If set, HWSCH will treat re-queue condition as same as
			pause. 
*/
#define SCHEDULER_CMD_1_FORCE_REQUEUE_TO_FILTER_OFFSET               0x00000004
#define SCHEDULER_CMD_1_FORCE_REQUEUE_TO_FILTER_LSB                  6
#define SCHEDULER_CMD_1_FORCE_REQUEUE_TO_FILTER_MASK                 0x00000040

/* Description		SCHEDULER_CMD_1_RESERVED_1A
			
			Reserved: Generator should set to 0, consumer shall
			ignore
			
			<legal 0>
*/
#define SCHEDULER_CMD_1_RESERVED_1A_OFFSET                           0x00000004
#define SCHEDULER_CMD_1_RESERVED_1A_LSB                              7
#define SCHEDULER_CMD_1_RESERVED_1A_MASK                             0x00000080

/* Description		SCHEDULER_CMD_1_RESERVED_1B
			
			Reserved: Generator should set to 0, consumer shall
			ignore
			
			<legal 0>
*/
#define SCHEDULER_CMD_1_RESERVED_1B_OFFSET                           0x00000004
#define SCHEDULER_CMD_1_RESERVED_1B_LSB                              8
#define SCHEDULER_CMD_1_RESERVED_1B_MASK                             0x00000300

/* Description		SCHEDULER_CMD_1_START_TIME_REFERENCE
			
			Indicates the reference clock to be used for checking
			the scheduling start time
			
			<enum 0 TSF1>
			
			<enum 1 TSF2>
			
			<enum 2 WB_Timer>
			
			<enum 3 queue_timer0> Internal scheduler command queue
			timer 0
			
			<enum 4 queue_timer1> Internal scheduler command queue
			timer 1
			
			<legal 0-4>
*/
#define SCHEDULER_CMD_1_START_TIME_REFERENCE_OFFSET                  0x00000004
#define SCHEDULER_CMD_1_START_TIME_REFERENCE_LSB                     10
#define SCHEDULER_CMD_1_START_TIME_REFERENCE_MASK                    0x00001c00

/* Description		SCHEDULER_CMD_1_END_TIME_REFERENCE
			
			Indicates the reference clock to be used for checking
			the lifetime expiration time of the command.
			
			<enum 0 TSF1>
			
			<enum 1 TSF2>
			
			<enum 2 WB_Timer>
			
			<enum 3 queue_timer0> Internal scheduler command queue
			timer 0
			
			<enum 4 queue_timer1> Internal scheduler command queue
			timer 1
			
			<legal 0-4>
*/
#define SCHEDULER_CMD_1_END_TIME_REFERENCE_OFFSET                    0x00000004
#define SCHEDULER_CMD_1_END_TIME_REFERENCE_LSB                       13
#define SCHEDULER_CMD_1_END_TIME_REFERENCE_MASK                      0x0000e000

/* Description		SCHEDULER_CMD_1_SCH_MAX_TXOP_TIME
			
			The maximum amount of TXOP time (in 4 us units).
			
			
			
			When field TXOP_time_ctrl is set to Basic:
			
			Scheduler will compare this value with other TXOP
			limiting inputs, for example how much time there is to TBTT.
			This is then the final available TXOP time, which is passed
			on to PDG in PDG transmit mode, or is used to compare
			against the FES_total_transmit time in case of SW transmit
			mode
			
			
			
			When field TXOP_time_ctrl is set to
			Start_after_bo_or_ongoing:
			
			If this is the first scheduling command called after BO
			expiration, the  scheduler initializes an internal TXOP
			timer with this value. The contents of that timer is
			compared with the other TXOP boundary timers (like TBTT),
			and passed on to the PDG in PDG transmit mode, or is used to
			compare against the FES_total_transmit time in case of SW
			transmit mode
			
			If this is this scheduling command is NOT the first
			first scheduling command called after BO expiration, this
			value is ignored. The scheduler will take the time value
			that is remaining in TXOP timer (initialized in earlier
			commands), and use that as the remaining max TXOP time. 
			This TXOP time is compared with the other TXOP boundaries,
			and the smallest one is selected, and passed on to PDG, or
			compared with FES_total_transmit time in case of SW transmit
			mode
			
			
			
			
			
			<legal all>
*/
#define SCHEDULER_CMD_1_SCH_MAX_TXOP_TIME_OFFSET                     0x00000004
#define SCHEDULER_CMD_1_SCH_MAX_TXOP_TIME_LSB                        16
#define SCHEDULER_CMD_1_SCH_MAX_TXOP_TIME_MASK                       0x3fff0000

/* Description		SCHEDULER_CMD_1_PAUSE_ON_FILTER
			
			This is the global control for SW to specify PAUSE
			during a BURST sequence.
*/
#define SCHEDULER_CMD_1_PAUSE_ON_FILTER_OFFSET                       0x00000004
#define SCHEDULER_CMD_1_PAUSE_ON_FILTER_LSB                          30
#define SCHEDULER_CMD_1_PAUSE_ON_FILTER_MASK                         0x40000000

/* Description		SCHEDULER_CMD_1_FILTER_ON_BW_FAILURE
			
			Filter this scheduler command if the required bandwidth
			for this scheduling command was higher than the available
			bandwidth.  If this bit is not set then this results in a
			quiet collision and new backoff without incrementing the
			transmit try count.  If this bit is set then the scheduling
			command is filtered. 
*/
#define SCHEDULER_CMD_1_FILTER_ON_BW_FAILURE_OFFSET                  0x00000004
#define SCHEDULER_CMD_1_FILTER_ON_BW_FAILURE_LSB                     31
#define SCHEDULER_CMD_1_FILTER_ON_BW_FAILURE_MASK                    0x80000000

/* Description		SCHEDULER_CMD_2_SCHEDULER_TLV_PTR
			
			The address location for the transmit TLVs.
			
			These TLVs get read/interpreted by the scheduler and
			when applicable pushed down the transmit chain to the other
			transmit modules. <legal all>
*/
#define SCHEDULER_CMD_2_SCHEDULER_TLV_PTR_OFFSET                     0x00000008
#define SCHEDULER_CMD_2_SCHEDULER_TLV_PTR_LSB                        0
#define SCHEDULER_CMD_2_SCHEDULER_TLV_PTR_MASK                       0xffffffff

/* Description		SCHEDULER_CMD_3_SCHEDULE_LIFETIME_EXP
			
			Scheduling command lifetime expiration time.
			
			A value of zero: Command never expires
			
			A non-zero value: the Timestamp at which the scheduler
			command expires. 
			
			Note that End_Time_reference indicates what the
			reference timer is.HW assumes the timer wraps around at 32
			bits, and checks that the actual reference time is within
			the programmed time and this value minus 2^31. If not, the
			lifetime is assumed to be expired.
			
			
			
			SCH and PDG will ensure that any transmission will not
			go over this lifetime. SCH will take this Lifetime boundary
			into account when calculating the remaining TXOP time.
			
			
			
			 <legal all>
*/
#define SCHEDULER_CMD_3_SCHEDULE_LIFETIME_EXP_OFFSET                 0x0000000c
#define SCHEDULER_CMD_3_SCHEDULE_LIFETIME_EXP_LSB                    0
#define SCHEDULER_CMD_3_SCHEDULE_LIFETIME_EXP_MASK                   0xffffffff

/* Description		SCHEDULER_CMD_4_SCHEDULE_START_TIME
			
			Scheduling command start time.
			
			A value of zero: Start time check is not enabled
			
			A non-zero value: the Timestamp before which the
			scheduler command may not be executed. The TX scheduler
			module will pause till this time is reached. Note that
			Start_Time_reference indicates what the reference timer is.
			
			HW assumes the timer wraps around at 32 bits, and checks
			that  the actual reference time is within the programmed
			time (schedule_start_time) and this value plus 2^31. If not,
			start time has not been reached yet. <legal all>
*/
#define SCHEDULER_CMD_4_SCHEDULE_START_TIME_OFFSET                   0x00000010
#define SCHEDULER_CMD_4_SCHEDULE_START_TIME_LSB                      0
#define SCHEDULER_CMD_4_SCHEDULE_START_TIME_MASK                     0xffffffff

/* Description		SCHEDULER_CMD_5_PEER_ENTRY_PTR0
			
			Pointer to the peer entry for user 0
			
			This pointer is used by the scheduler to initially check
			if the STA is in power save mode or not. (this check can be
			enabled with sta_pwr_state_chk_en field)
			
			
			
			<legal all>
*/
#define SCHEDULER_CMD_5_PEER_ENTRY_PTR0_OFFSET                       0x00000014
#define SCHEDULER_CMD_5_PEER_ENTRY_PTR0_LSB                          0
#define SCHEDULER_CMD_5_PEER_ENTRY_PTR0_MASK                         0xffffffff

/* Description		SCHEDULER_CMD_6_PEER_ENTRY_PTR1
			
			This entry is NOT valid when equal to 0.
			
			
			
			Pointer to the peer entry for user 1
			
			This pointer is used by the scheduler to initially check
			if the STA is in power save mode or not. (this check can be
			enabled with sta_pwr_state_chk_en field)
			
			<legal all>
*/
#define SCHEDULER_CMD_6_PEER_ENTRY_PTR1_OFFSET                       0x00000018
#define SCHEDULER_CMD_6_PEER_ENTRY_PTR1_LSB                          0
#define SCHEDULER_CMD_6_PEER_ENTRY_PTR1_MASK                         0xffffffff

/* Description		SCHEDULER_CMD_7_PEER_ENTRY_PTR2
			
			This entry is NOT valid when equal to 0.
			
			
			
			Pointer to the peer entry for user 2
			
			This pointer is used by the scheduler to initially check
			if the STA is in power save mode or not. (this check can be
			enabled with sta_pwr_state_chk_en field)
			
			
			
			
			
			<legal all>
*/
#define SCHEDULER_CMD_7_PEER_ENTRY_PTR2_OFFSET                       0x0000001c
#define SCHEDULER_CMD_7_PEER_ENTRY_PTR2_LSB                          0
#define SCHEDULER_CMD_7_PEER_ENTRY_PTR2_MASK                         0xffffffff


#endif // _SCHEDULER_CMD_H_
