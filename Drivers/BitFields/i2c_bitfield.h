

#ifndef REGS_I2C_PMBUS_SMBUS_H
#define REGS_I2C_PMBUS_SMBUS_H

#ifdef __cplusplus
extern "C" {
#endif



struct IC_CON_BITS {			// bits   description
	uint32_t	MASTER_MODE:1;			// 0:0   This bit controls whether the DW_apb_i2c master is enabled.

	uint32_t	SPEED:2;			// 2:1   These bits control at which speed the DW_apb_i2c operates; its setting is relevant only if one is operating
	uint32_t	IC_10BITADDR_SLAVE:1;			// 3:3   When acting as a slave, this bit controls whether the DW_apb_i2c responds to 7- or 10-bit addresses.

	uint32_t	IC_10BITADDR_MASTER:1;			// 4:4   If the I2C_DYNAMIC_TAR_UPDATE configuration parameter is set to 'No' (0), this bit is named IC_10BITADDR_MASTER
	uint32_t	IC_RESTART_EN:1;			// 5:5   Determines whether RESTART conditions may be sent when acting as a master. Some older slaves do not support
	uint32_t	IC_SLAVE_DISABLE:1;			// 6:6   This bit controls whether I2C has its slave disabled, which means once the presetn signal is applied,
	uint32_t	STOP_DET_IFADDRESSED:1;			// 7:7   In slave mode:

	uint32_t	TX_EMPTY_CTRL:1;			// 8:8   This bit controls the generation of the TX_EMPTY interrupt, as described in the IC_RAW_INTR_STAT register.

	uint32_t	RX_FIFO_FULL_HLD_CTRL:1;			// 9:9   This bit controls whether DW_apb_i2c should hold the bus when the Rx FIFO is physically full to its RX_BUFFER_DEPTH,
	uint32_t	STOP_DET_IF_MASTER_ACTIVE:1;			// 10:10   In Master mode:

	uint32_t	BUS_CLEAR_FEATURE_CTRL:1;			// 11:11   This bit controls whether the DW_apb_i2c enables the bus clear feature. For more information, refer to
	uint32_t	rsvd1:5;			// 16:12   reserved
	uint32_t	SMBUS_SLAVE_QUICK_EN:1;			// 17:17   If this bit is set to 1, DW_apb_i2c slave only receives Quick commands in SMBus Mode.

	uint32_t	SMBUS_ARP_EN:1;			// 18:18   This bit controls whether DW_apb_i2c should enable Address Resolution Logic in SMBus Mode. The Slave
	uint32_t	SMBUS_PERSISTENT_SLV_ADDR_EN:1;			// 19:19   The bit controls to enable DW_apb_i2c slave as persistent or non persistent slave.

	uint32_t	SMBUS_PERSISTENT_SLV_ADDR2_EN:1;			// 20:20   The bit controls to enable DW_apb_i2c slave with Slave address 2 (IC_SAR2) as persistent or non persistent
	uint32_t	rsvd2:2;			// 22:21   reserved
	uint32_t	IC_SAR2_SMBUS_ARP_EN:1;			// 23:23   This bit controls whether DW_apb_i2c should enable Address Resolution Logic in SMBus Mode for IC_SAR2
	uint32_t	rsvd3:8;			// 31:24   reserved
};

union IC_CON_REG {
	uint32_t 		 all;
	struct IC_CON_BITS 		 bit;
};

struct IC_TAR_BITS {			// bits   description
	uint32_t	IC_TAR:10;			// 9:0   This is the target address for any master transaction. When transmitting a General Call, these bits are
	uint32_t	GC_OR_START:1;			// 10:10   If bit 11 (SPECIAL) is set to 1 and bit 13(Device-ID) is set to 0, then this bit indicates whether a
	uint32_t	SPECIAL:1;			// 11:11   This bit indicates whether software performs a Device-ID or General Call or START BYTE command.

	uint32_t	rsvd1:4;			// 15:12   reserved
	uint32_t	SMBUS_QUICK_CMD:1;			// 16:16   If bit 11 (SPECIAL) is set to 1, then this bit indicates whether a Quick command is to be performed by
	uint32_t	rsvd2:15;			// 31:17   reserved
};

union IC_TAR_REG {
	uint32_t 		 all;
	struct IC_TAR_BITS 		 bit;
};

struct IC_SAR_BITS {			// bits   description
	uint32_t	IC_SAR:10;			// 9:0   The IC_SAR holds the slave address when the I2C is operating as a slave. For 7-bit addressing, only IC_SAR[6:0]
	uint32_t	rsvd1:22;			// 31:10   reserved
};

union IC_SAR_REG {
	uint32_t 		 all;
	struct IC_SAR_BITS 		 bit;
};

struct IC_DATA_CMD_BITS {			// bits   description
	uint32_t	DAT:8;			// 7:0   This register contains the data to be transmitted or received on the I2C bus. If you are writing to this
	uint32_t	CMD:1;			// 8:8   This bit controls whether a read or a write is performed. This bit does not control the direction when
	uint32_t	STOP:1;			// 9:9   This bit controls whether a STOP is issued after the byte is sent or received. This bit is available
	uint32_t	RESTART:1;			// 10:10   This bit controls whether a RESTART is issued before the byte is sent or received. This bit is available
	uint32_t	rsvd1:21;			// 31:11   reserved
};

union IC_DATA_CMD_REG {
	uint32_t 		 all;
	struct IC_DATA_CMD_BITS 		 bit;
};

struct IC_SS_SCL_HCNT_BITS {			// bits   description
	uint32_t	IC_SS_SCL_HCNT:16;			// 15:0   This register must be set before any I2C bus transaction can take place to ensure proper I/O timing.
	uint32_t	rsvd1:16;			// 31:16   reserved
};

union IC_SS_SCL_HCNT_REG {
	uint32_t 		 all;
	struct IC_SS_SCL_HCNT_BITS 		 bit;
};

struct IC_SS_SCL_LCNT_BITS {			// bits   description
	uint32_t	IC_SS_SCL_LCNT:16;			// 15:0   This register must be set before any I2C bus transaction can take place to ensure proper I/O timing.
	uint32_t	rsvd1:16;			// 31:16   reserved
};

union IC_SS_SCL_LCNT_REG {
	uint32_t 		 all;
	struct IC_SS_SCL_LCNT_BITS 		 bit;
};

struct IC_FS_SCL_HCNT_BITS {			// bits   description
	uint32_t	IC_FS_SCL_HCNT:16;			// 15:0   This register must be set before any I2C bus transaction can take place to ensure proper I/O timing.
	uint32_t	rsvd1:16;			// 31:16   reserved
};

union IC_FS_SCL_HCNT_REG {
	uint32_t 		 all;
	struct IC_FS_SCL_HCNT_BITS 		 bit;
};

struct IC_FS_SCL_LCNT_BITS {			// bits   description
	uint32_t	IC_FS_SCL_LCNT:16;			// 15:0   This register must be set before any I2C bus transaction can take place to ensure proper I/O timing.
	uint32_t	rsvd1:16;			// 31:16   reserved
};

union IC_FS_SCL_LCNT_REG {
	uint32_t 		 all;
	struct IC_FS_SCL_LCNT_BITS 		 bit;
};

struct IC_INTR_STAT_BITS {			// bits   description
	uint32_t	R_RX_UNDER:1;			// 0:0   Set if the processor attempts to read the receive buffer when it is empty by reading from the IC_DATA_CMD
	uint32_t	R_RX_OVER:1;			// 1:1   Set if the receive buffer is completely filled to IC_RX_BUFFER_DEPTH and an additional byte is received
	uint32_t	R_RX_FULL:1;			// 2:2   Set when the receive buffer reaches or goes above the RX_TL threshold in the IC_RX_TL register. It is
	uint32_t	R_TX_OVER:1;			// 3:3   Set during transmit if the transmit buffer is filled to IC_TX_BUFFER_DEPTH and the processor attempts
	uint32_t	R_TX_EMPTY:1;			// 4:4   The behavior of the TX_EMPTY interrupt status differs based on the TX_EMPTY_CTRL selection in the IC_CON
	uint32_t	R_RD_REQ:1;			// 5:5   This bit is set to 1 when DW_apb_i2c is acting as a slave and another I2C master is attempting to read
	uint32_t	R_TX_ABRT:1;			// 6:6   This bit indicates if DW_apb_i2c, as an I2C transmitter, is unable to complete the intended actions on
	uint32_t	R_RX_DONE:1;			// 7:7   When the DW_apb_i2c is acting as a slave-transmitter, this bit is set to 1 if the master does not acknowledge
	uint32_t	R_ACTIVITY:1;			// 8:8   This bit captures DW_apb_i2c activity and stays set until it is cleared. There are four ways to clear
	uint32_t	R_STOP_DET:1;			// 9:9   Indicates whether a STOP condition has occurred on the I2C interface regardless of whether DW_apb_i2c
	uint32_t	R_START_DET:1;			// 10:10   Indicates whether a START or RESTART condition has occurred on the I2C interface regardless of whether
	uint32_t	R_GEN_CALL:1;			// 11:11   Set only when a General Call address is received and it is acknowledged. It stays set until it is cleared
	uint32_t	R_RESTART_DET:1;			// 12:12   Indicates whether a RESTART condition has occurred on the I2C interface when DW_apb_i2c is operating
	uint32_t	R_MASTER_ON_HOLD:1;			// 13:13   Indicates whether master is holding the bus and TX FIFO is empty. Enabled only when I2C_DYNAMIC_TAR_UPDATE=1
	uint32_t	R_SCL_STUCK_AT_LOW:1;			// 14:14   Indicates whether the SCL Line is stuck at low for the IC_SCL_STUCK_LOW_TIMEOUT number of ic_clk periods.

	uint32_t	R_WR_REQ:1;			// 15:15   This bit is set to 1 when DW_apb_i2c is acting as slave and another I2C master is attempting to werite
	uint32_t	R_SLV_ADDR1_TAG:1;			// 16:16   This bit is set to 1 when DW_apb_i2c is acting as slave and another I2C master is attempting to write/read
	uint32_t	R_SLV_ADDR2_TAG:1;			// 17:17   This bit is set to 1 when DW_apb_i2c is acting as slave and another I2C master is attempting to write/read
	uint32_t	rsvd1:14;			// 31:18   reserved
};

union IC_INTR_STAT_REG {
	uint32_t 		 all;
	struct IC_INTR_STAT_BITS 		 bit;
};

struct IC_INTR_MASK_BITS {			// bits   description
	uint32_t	M_RX_UNDER:1;			// 0:0   This bit masks the R_RX_UNDER interrupt in IC_INTR_STAT register.

	uint32_t	M_RX_OVER:1;			// 1:1   This bit masks the R_RX_OVER interrupt in IC_INTR_STAT register.

	uint32_t	M_RX_FULL:1;			// 2:2   This bit masks the R_RX_FULL interrupt in IC_INTR_STAT register.

	uint32_t	M_TX_OVER:1;			// 3:3   This bit masks the R_TX_OVER interrupt in IC_INTR_STAT register.

	uint32_t	M_TX_EMPTY:1;			// 4:4   This bit masks the R_TX_EMPTY interrupt in IC_INTR_STAT register.

	uint32_t	M_RD_REQ:1;			// 5:5   This bit masks the R_RD_REQ interrupt in IC_INTR_STAT register.

	uint32_t	M_TX_ABRT:1;			// 6:6   This bit masks the R_TX_ABRT interrupt in IC_INTR_STAT register.

	uint32_t	M_RX_DONE:1;			// 7:7   This bit masks the R_RX_DONE interrupt in IC_INTR_STAT register.

	uint32_t	M_ACTIVITY:1;			// 8:8   This bit masks the R_ACTIVITY interrupt in IC_INTR_STAT register.

	uint32_t	M_STOP_DET:1;			// 9:9   This bit masks the R_STOP_DET interrupt in IC_INTR_STAT register.

	uint32_t	M_START_DET:1;			// 10:10   This bit masks the R_START_DET interrupt in IC_INTR_STAT register.

	uint32_t	M_GEN_CALL:1;			// 11:11   This bit masks the R_GEN_CALL interrupt in IC_INTR_STAT register.

	uint32_t	M_RESTART_DET:1;			// 12:12   This bit masks the R_RESTART_DET interrupt in IC_INTR_STAT register.

	uint32_t	M_MASTER_ON_HOLD_READ_ONLY:1;			// 13:13   This M_MASTER_ON_HOLD_read_only bit masks the R_MASTER_ON_HOLD interrupt in IC_INTR_STAT register.

	uint32_t	M_SCL_STUCK_AT_LOW:1;			// 14:14   This bit masks the R_SCL_STUCK_AT_LOW interrupt in IC_INTR_STAT register.

	uint32_t	M_WR_REQ:1;			// 15:15   This bit masks the R_WR_REQ interrupt in IC_INTR_STAT register.

	uint32_t	M_SLV_ADDR1_TAG:1;			// 16:16   This bit masks the R_SLV_ADDR1_TAG interrupt in IC_INTR_STAT register.

	uint32_t	M_SLV_ADDR2_TAG:1;			// 17:17   This bit masks the R_SLV_ADDR2_TAG interrupt in IC_INTR_STAT register.

	uint32_t	rsvd1:14;			// 31:18   reserved
};

union IC_INTR_MASK_REG {
	uint32_t 		 all;
	struct IC_INTR_MASK_BITS 		 bit;
};

struct IC_RAW_INTR_STAT_BITS {			// bits   description
	uint32_t	RX_UNDER:1;			// 0:0   Set if the processor attempts to read the receive buffer when it is empty by reading from the IC_DATA_CMD
	uint32_t	RX_OVER:1;			// 1:1   Set if the receive buffer is completely filled to IC_RX_BUFFER_DEPTH and an additional byte is received
	uint32_t	RX_FULL:1;			// 2:2   Set when the receive buffer reaches or goes above the RX_TL threshold in the IC_RX_TL register. It is
	uint32_t	TX_OVER:1;			// 3:3   Set during transmit if the transmit buffer is filled to IC_TX_BUFFER_DEPTH and the processor attempts
	uint32_t	TX_EMPTY:1;			// 4:4   The behavior of the TX_EMPTY interrupt status differs based on the TX_EMPTY_CTRL selection in the IC_CON
	uint32_t	RD_REQ:1;			// 5:5   This bit is set to 1 when DW_apb_i2c is acting as a slave and another I2C master is attempting to read
	uint32_t	TX_ABRT:1;			// 6:6   This bit indicates if DW_apb_i2c, as an I2C transmitter, is unable to complete the intended actions on
	uint32_t	RX_DONE:1;			// 7:7   When the DW_apb_i2c is acting as a slave-transmitter, this bit is set to 1 if the master does not acknowledge
	uint32_t	ACTIVITY:1;			// 8:8   This bit captures DW_apb_i2c activity and stays set until it is cleared. There are four ways to clear
	uint32_t	STOP_DET:1;			// 9:9   Indicates whether a STOP condition has occurred on the I2C interface regardless of whether DW_apb_i2c
	uint32_t	START_DET:1;			// 10:10   Indicates whether a START or RESTART condition has occurred on the I2C interface regardless of whether
	uint32_t	GEN_CALL:1;			// 11:11   Set only when a General Call address is received and it is acknowledged. It stays set until it is cleared
	uint32_t	RESTART_DET:1;			// 12:12   Indicates whether a RESTART condition has occurred on the I2C interface when DW_apb_i2c is operating
	uint32_t	MASTER_ON_HOLD:1;			// 13:13   Indicates whether master is holding the bus and TX FIFO is empty. Enabled only when I2C_DYNAMIC_TAR_UPDATE=1
	uint32_t	SCL_STUCK_AT_LOW:1;			// 14:14   Indicates whether the SCL Line is stuck at low for the IC_SCL_STUCK_LOW_TIMEOUT number of ic_clk periods.

	uint32_t	WR_REQ:1;			// 15:15   This bit is set to 1 when DW_apb_i2c is acting as slave and another I2C master is attempting to werite
	uint32_t	SLV_ADDR1_TAG:1;			// 16:16   This bit is set to 1 when DW_apb_i2c is acting as slave and another I2C master is attempting to write/read
	uint32_t	SLV_ADDR2_TAG:1;			// 17:17   This bit is set to 1 when DW_apb_i2c is acting as slave and another I2C master is attempting to write/read
	uint32_t	rsvd1:14;			// 31:18   reserved
};

union IC_RAW_INTR_STAT_REG {
	uint32_t 		 all;
	struct IC_RAW_INTR_STAT_BITS 		 bit;
};

struct IC_RX_TL_BITS {			// bits   description
	uint32_t	RX_TL:1;			// 0:0   Receive FIFO Threshold Level.

	uint32_t	rsvd1:31;			// 31:1   reserved
};

union IC_RX_TL_REG {
	uint32_t 		 all;
	struct IC_RX_TL_BITS 		 bit;
};

struct IC_TX_TL_BITS {			// bits   description
	uint32_t	TX_TL:1;			// 0:0   Transmit FIFO Threshold Level.

	uint32_t	rsvd1:31;			// 31:1   reserved
};

union IC_TX_TL_REG {
	uint32_t 		 all;
	struct IC_TX_TL_BITS 		 bit;
};

struct IC_CLR_INTR_BITS {			// bits   description
	uint32_t	CLR_INTR:1;			// 0:0   Read this register to clear the combined interrupt, all individual interrupts, and the IC_TX_ABRT_SOURCE
	uint32_t	rsvd1:31;			// 31:1   reserved
};

union IC_CLR_INTR_REG {
	uint32_t 		 all;
	struct IC_CLR_INTR_BITS 		 bit;
};

struct IC_CLR_RX_UNDER_BITS {			// bits   description
	uint32_t	CLR_RX_UNDER:1;			// 0:0   Read this register to clear the RX_UNDER interrupt (bit 0) of the IC_RAW_INTR_STAT register.
	uint32_t	rsvd1:31;			// 31:1   reserved
};

union IC_CLR_RX_UNDER_REG {
	uint32_t 		 all;
	struct IC_CLR_RX_UNDER_BITS 		 bit;
};

struct IC_CLR_RX_OVER_BITS {			// bits   description
	uint32_t	CLR_RX_OVER:1;			// 0:0   Read this register to clear the RX_OVER interrupt (bit 1) of the IC_RAW_INTR_STAT register.
	uint32_t	rsvd1:31;			// 31:1   reserved
};

union IC_CLR_RX_OVER_REG {
	uint32_t 		 all;
	struct IC_CLR_RX_OVER_BITS 		 bit;
};

struct IC_CLR_TX_OVER_BITS {			// bits   description
	uint32_t	CLR_TX_OVER:1;			// 0:0   Read this register to clear the TX_OVER interrupt (bit 3) of the IC_RAW_INTR_STAT register.
	uint32_t	rsvd1:31;			// 31:1   reserved
};

union IC_CLR_TX_OVER_REG {
	uint32_t 		 all;
	struct IC_CLR_TX_OVER_BITS 		 bit;
};

struct IC_CLR_RD_REQ_BITS {			// bits   description
	uint32_t	CLR_RD_REQ:1;			// 0:0   Read this register to clear the RD_REQ interrupt (bit 5) of the IC_RAW_INTR_STAT register.
	uint32_t	rsvd1:31;			// 31:1   reserved
};

union IC_CLR_RD_REQ_REG {
	uint32_t 		 all;
	struct IC_CLR_RD_REQ_BITS 		 bit;
};

struct IC_CLR_TX_ABRT_BITS {			// bits   description
	uint32_t	CLR_TX_ABRT:1;			// 0:0   Read this register to clear the TX_ABRT interrupt (bit 6) of the IC_RAW_INTR_STAT register, and the IC_TX_ABRT_SOURCE
	uint32_t	rsvd1:31;			// 31:1   reserved
};

union IC_CLR_TX_ABRT_REG {
	uint32_t 		 all;
	struct IC_CLR_TX_ABRT_BITS 		 bit;
};

struct IC_CLR_RX_DONE_BITS {			// bits   description
	uint32_t	CLR_RX_DONE:1;			// 0:0   Read this register to clear the RX_DONE interrupt (bit 7) of the IC_RAW_INTR_STAT register.
	uint32_t	rsvd1:31;			// 31:1   reserved
};

union IC_CLR_RX_DONE_REG {
	uint32_t 		 all;
	struct IC_CLR_RX_DONE_BITS 		 bit;
};

struct IC_CLR_ACTIVITY_BITS {			// bits   description
	uint32_t	CLR_ACTIVITY:1;			// 0:0   Reading this register clears the ACTIVITY interrupt if the I2C is not active anymore. If the I2C module
	uint32_t	rsvd1:31;			// 31:1   reserved
};

union IC_CLR_ACTIVITY_REG {
	uint32_t 		 all;
	struct IC_CLR_ACTIVITY_BITS 		 bit;
};

struct IC_CLR_STOP_DET_BITS {			// bits   description
	uint32_t	CLR_STOP_DET:1;			// 0:0   Read this register to clear the STOP_DET interrupt (bit 9) of the IC_RAW_INTR_STAT register.
	uint32_t	rsvd1:31;			// 31:1   reserved
};

union IC_CLR_STOP_DET_REG {
	uint32_t 		 all;
	struct IC_CLR_STOP_DET_BITS 		 bit;
};

struct IC_CLR_START_DET_BITS {			// bits   description
	uint32_t	CLR_START_DET:1;			// 0:0   Read this register to clear the START_DET interrupt (bit 10) of the IC_RAW_INTR_STAT register.
	uint32_t	rsvd1:31;			// 31:1   reserved
};

union IC_CLR_START_DET_REG {
	uint32_t 		 all;
	struct IC_CLR_START_DET_BITS 		 bit;
};

struct IC_CLR_GEN_CALL_BITS {			// bits   description
	uint32_t	CLR_GEN_CALL:1;			// 0:0   Read this register to clear the GEN_CALL interrupt (bit 11) of IC_RAW_INTR_STAT register.
	uint32_t	rsvd1:31;			// 31:1   reserved
};

union IC_CLR_GEN_CALL_REG {
	uint32_t 		 all;
	struct IC_CLR_GEN_CALL_BITS 		 bit;
};

struct IC_ENABLE_BITS {			// bits   description
	uint32_t	ENABLE:1;			// 0:0   Controls whether the DW_apb_i2c is enabled.

	uint32_t	ABORT:1;			// 1:1   When set, the controller initiates the transfer abort.

	uint32_t	rsvd1:1;			// 2:2   reserved
	uint32_t	SDA_STUCK_RECOVERY_ENABLE:1;			// 3:3   If SDA is stuck at low indicated through the TX_ABORT interrupt (IC_TX_ABRT_SOURCE[17]), then this bit
	uint32_t	rsvd2:12;			// 15:4   reserved
	uint32_t	SMBUS_CLK_RESET:1;			// 16:16   This bit is used in SMBus Host mode to initiate the SMBus Master Clock Reset. This bit should be enabled
	uint32_t	SMBUS_SUSPEND_EN:1;			// 17:17   The SMBUS_SUSPEND_EN register bit is used to control assertion and de-assertion of SMBSUS signal.

	uint32_t	SMBUS_ALERT_EN:1;			// 18:18   The SMBUS_ALERT_CTRL register bit is used to control assertion of SMBALERT signal.

	uint32_t	IC_SAR_EN:1;			// 19:19   Controls whether the DW_apb_i2c SAR is enabled.

	uint32_t	IC_SAR2_EN:1;			// 20:20   Controls whether the DW_apb_i2c SAR2 is enabled.

	uint32_t	rsvd3:11;			// 31:21   reserved
};

union IC_ENABLE_REG {
	uint32_t 		 all;
	struct IC_ENABLE_BITS 		 bit;
};

struct IC_STATUS_BITS {			// bits   description
	uint32_t	ACTIVITY:1;			// 0:0   I2C Activity Status.

	uint32_t	TFNF:1;			// 1:1   Transmit FIFO Not Full. Set when the transmit FIFO contains one or more empty locations, and is cleared
	uint32_t	TFE:1;			// 2:2   Transmit FIFO Completely Empty. When the transmit FIFO is completely empty, this bit is set. When it
	uint32_t	RFNE:1;			// 3:3   Receive FIFO Not Empty. This bit is set when the receive FIFO contains one or more entries; it is cleared
	uint32_t	RFF:1;			// 4:4   Receive FIFO Completely Full. When the receive FIFO is completely full, this bit is set. When the receive
	uint32_t	MST_ACTIVITY:1;			// 5:5   Master FSM Activity Status. When the Master Finite State Machine (FSM) is not in the IDLE state, this
	uint32_t	SLV_ACTIVITY:1;			// 6:6   Slave FSM Activity Status. When the Slave Finite State Machine (FSM) is not in the IDLE state, this bit
	uint32_t	rsvd1:4;			// 10:7   reserved
	uint32_t	SDA_STUCK_NOT_RECOVERED:1;			// 11:11   This bit indicates that SDA stuck at low is not recovered after the recovery mechanism. In Slave mode,
	uint32_t	rsvd2:4;			// 15:12   reserved
	uint32_t	SMBUS_QUICK_CMD_BIT:1;			// 16:16   This bit indicates the R/W bit of the Quick command received. This bit will be cleared after the user
	uint32_t	SMBUS_SLAVE_ADDR_VALID:1;			// 17:17   This bit indicates whether the slave address (ic_sar) is valid or not.

	uint32_t	SMBUS_SLAVE_ADDR_RESOLVED:1;			// 18:18   This bit indicates whether the slave address (ic_sar) is resolved by the ARP Master.

	uint32_t	SMBUS_SUSPEND_STATUS:1;			// 19:19   This bit indicates the status of the SMBus Suspend signal (ic_smbsus_in_n). This signal is asserted when
	uint32_t	SMBUS_ALERT_STATUS:1;			// 20:20   This bit indicates the status of the SMBus Alert signal (ic_smbalert_in_n). This signal is asserted when
	uint32_t	SMBUS_SLAVE_ADDR2_VALID:1;			// 21:21   This bit indicates whether the slave address 2 (IC_SAR2) is valid or not.

	uint32_t	SMBUS_SLAVE_ADDR2_RESOLVED:1;			// 22:22   This bit indicates whether the slave address 2 (IC_SAR2) is resolved by the ARP Master.

	uint32_t	rsvd3:9;			// 31:23   reserved
};

union IC_STATUS_REG {
	uint32_t 		 all;
	struct IC_STATUS_BITS 		 bit;
};

struct IC_TXFLR_BITS {			// bits   description
	uint32_t	TXFLR:5;			// 4:0   Transmit FIFO Level. Contains the number of valid data entries in the transmit FIFO.
	uint32_t	rsvd1:27;			// 31:5   reserved
};

union IC_TXFLR_REG {
	uint32_t 		 all;
	struct IC_TXFLR_BITS 		 bit;
};

struct IC_RXFLR_BITS {			// bits   description
	uint32_t	RXFLR:5;			// 4:0   Receive FIFO Level. Contains the number of valid data entries in the receive FIFO.
	uint32_t	rsvd1:27;			// 31:5   reserved
};

union IC_RXFLR_REG {
	uint32_t 		 all;
	struct IC_RXFLR_BITS 		 bit;
};

struct IC_SDA_HOLD_BITS {			// bits   description
	uint32_t	IC_SDA_TX_HOLD:16;			// 15:0   Sets the required SDA hold time in units of ic_clk period, when DW_apb_i2c acts as a transmitter.
	uint32_t	IC_SDA_RX_HOLD:8;			// 23:16   Sets the required SDA hold time in units of ic_clk period, when DW_apb_i2c acts as a receiver.
	uint32_t	rsvd1:8;			// 31:24   reserved
};

union IC_SDA_HOLD_REG {
	uint32_t 		 all;
	struct IC_SDA_HOLD_BITS 		 bit;
};

struct IC_TX_ABRT_SOURCE_BITS {			// bits   description
	uint32_t	ABRT_7B_ADDR_NOACK:1;			// 0:0   This field indicates that the Master is in 7-bit addressing mode and the address sent was not acknowledged
	uint32_t	ABRT_10ADDR1_NOACK:1;			// 1:1   This field indicates that the Master is in 10-bit address mode and the first 10-bit address byte was
	uint32_t	ABRT_10ADDR2_NOACK:1;			// 2:2   This field indicates that the Master is in 10-bit address mode and that the second address byte of the
	uint32_t	ABRT_TXDATA_NOACK:1;			// 3:3   This field indicates the master-mode only bit. When the master receives an acknowledgement for the address,
	uint32_t	ABRT_GCALL_NOACK:1;			// 4:4   This field indicates that DW_apb_i2c in master mode has sent a General Call and no slave on the bus acknowledged
	uint32_t	ABRT_GCALL_READ:1;			// 5:5   This field indicates that DW_apb_i2c in the master mode has sent a General Call but the user programmed
	uint32_t	ABRT_HS_ACKDET:1;			// 6:6   This field indicates that the Master is in High Speed mode and the High Speed Master code was acknowledged
	uint32_t	ABRT_SBYTE_ACKDET:1;			// 7:7   This field indicates that the Master has sent a START Byte and the START Byte was acknowledged (wrong
	uint32_t	ABRT_HS_NORSTRT:1;			// 8:8   This field indicates that the restart is disabled (IC_RESTART_EN bit (IC_CON[5]) =0) and the user is
	uint32_t	ABRT_SBYTE_NORSTRT:1;			// 9:9   To clear Bit 9, the source of the ABRT_SBYTE_NORSTRT must be fixed first; restart must be enabled (IC_CON[5]=1),
	uint32_t	ABRT_10B_RD_NORSTRT:1;			// 10:10   This field indicates that the restart is disabled (IC_RESTART_EN bit (IC_CON[5]) =0) and the master sends
	uint32_t	ABRT_MASTER_DIS:1;			// 11:11   This field indicates that the User tries to initiate a Master operation with the Master mode disabled.

	uint32_t	ARB_LOST:1;			// 12:12   This field specifies that the Master has lost arbitration, or if IC_TX_ABRT_SOURCE[14] is also set, then
	uint32_t	ABRT_SLVFLUSH_TXFIFO:1;			// 13:13   This field specifies that the Slave has received a read command and some data exists in the TX FIFO,
	uint32_t	ABRT_SLV_ARBLOST:1;			// 14:14   This field indicates that a Slave has lost the bus while transmitting data to a remote master. IC_TX_ABRT_SOURCE[12]
	uint32_t	ABRT_SLVRD_INTX:1;			// 15:15   When the processor side responds to a slave mode request for data to be transmitted to a remote master
	uint32_t	ABRT_USER_ABRT:1;			// 16:16   This is a master-mode-only bit. Master has detected the transfer abort (IC_ENABLE[1])

	uint32_t	ABRT_SDA_STUCK_AT_LOW:1;			// 17:17   This is a master-mode-only bit. Master detects the SDA Stuck at low for the IC_SDA_STUCK_AT_LOW_TIMEOUT
	uint32_t	rsvd1:5;			// 22:18   reserved
	uint32_t	TX_FLUSH_CNT:9;			// 31:23   This field indicates the number of Tx FIFO Data Commands which are flushed due to TX_ABRT interrupt.
};

union IC_TX_ABRT_SOURCE_REG {
	uint32_t 		 all;
	struct IC_TX_ABRT_SOURCE_BITS 		 bit;
};

struct IC_DMA_CR_BITS {			// bits   description
	uint32_t	RDMAE:1;			// 0:0   Receive DMA Enable. This bit enables/disables the receive FIFO DMA channel.

	uint32_t	TDMAE:1;			// 1:1   Transmit DMA Enable. This bit enables/disables the transmit FIFO DMA channel.

	uint32_t	rsvd1:30;			// 31:2   reserved
};

union IC_DMA_CR_REG {
	uint32_t 		 all;
	struct IC_DMA_CR_BITS 		 bit;
};

struct IC_DMA_TDLR_BITS {			// bits   description
	uint32_t	DMATDL:4;			// 3:0   Transmit Data Level. This bit field controls the level at which a DMA request is made by the transmit
	uint32_t	rsvd1:28;			// 31:4   reserved
};

union IC_DMA_TDLR_REG {
	uint32_t 		 all;
	struct IC_DMA_TDLR_BITS 		 bit;
};

struct IC_DMA_RDLR_BITS {			// bits   description
	uint32_t	DMARDL:4;			// 3:0   Receive Data Level. This bit field controls the level at which a DMA request is made by the receive logic.
	uint32_t	rsvd1:28;			// 31:4   reserved
};

union IC_DMA_RDLR_REG {
	uint32_t 		 all;
	struct IC_DMA_RDLR_BITS 		 bit;
};

struct IC_SDA_SETUP_BITS {			// bits   description
	uint32_t	SDA_SETUP:8;			// 7:0   SDA Setup (tSU:DAT).

	uint32_t	rsvd1:24;			// 31:8   reserved
};

union IC_SDA_SETUP_REG {
	uint32_t 		 all;
	struct IC_SDA_SETUP_BITS 		 bit;
};

struct IC_ACK_GENERAL_CALL_BITS {			// bits   description
	uint32_t	ACK_GEN_CALL:1;			// 0:0   ACK General Call. When set to 1, DW_apb_i2c responds with a ACK (by asserting ic_data_oe) when it receives
	uint32_t	rsvd1:31;			// 31:1   reserved
};

union IC_ACK_GENERAL_CALL_REG {
	uint32_t 		 all;
	struct IC_ACK_GENERAL_CALL_BITS 		 bit;
};

struct IC_ENABLE_STATUS_BITS {			// bits   description
	uint32_t	IC_EN:1;			// 0:0   IC Enable Status. This bit always reflects the value driven on the output port ic_en.

	uint32_t	SLV_DISABLED_WHILE_BUSY:1;			// 1:1   Slave Disabled While Busy (Transmit, Receive). This bit indicates if a potential or active Slave operation
	uint32_t	SLV_RX_DATA_LOST:1;			// 2:2   Slave Received Data Lost. This bit indicates if a Slave-Receiver operation has been aborted with at least
	uint32_t	rsvd1:29;			// 31:3   reserved
};

union IC_ENABLE_STATUS_REG {
	uint32_t 		 all;
	struct IC_ENABLE_STATUS_BITS 		 bit;
};

struct IC_FS_SPKLEN_BITS {			// bits   description
	uint32_t	IC_FS_SPKLEN:8;			// 7:0   This register must be set before any I2C bus transaction can take place to ensure stable operation. This
	uint32_t	rsvd1:24;			// 31:8   reserved
};

union IC_FS_SPKLEN_REG {
	uint32_t 		 all;
	struct IC_FS_SPKLEN_BITS 		 bit;
};

struct IC_CLR_RESTART_DET_BITS {			// bits   description
	uint32_t	CLR_RESTART_DET:1;			// 0:0   Read this register to clear the RESTART_DET interrupt (bit 12) of IC_RAW_INTR_STAT register.
	uint32_t	rsvd1:31;			// 31:1   reserved
};

union IC_CLR_RESTART_DET_REG {
	uint32_t 		 all;
	struct IC_CLR_RESTART_DET_BITS 		 bit;
};

struct IC_SCL_STUCK_AT_LOW_TIMEOUT_BITS {			// bits   description
	uint32_t	IC_SCL_STUCK_LOW_TIMEOUT:32;			// 31:0   DW_apb_i2c generate the interrupt to indicate SCL stuck at low (ic_scl_stuck_at_low_intr/ic_scl_stuck_at_low_intr_n)
};

union IC_SCL_STUCK_AT_LOW_TIMEOUT_REG {
	uint32_t 		 all;
	struct IC_SCL_STUCK_AT_LOW_TIMEOUT_BITS 		 bit;
};

struct IC_SDA_STUCK_AT_LOW_TIMEOUT_BITS {			// bits   description
	uint32_t	IC_SDA_STUCK_LOW_TIMEOUT:32;			// 31:0   DW_apb_i2c initiates the recovery of SDA line through enabling the SDA_STUCK_RECOVERY_EN (IC_ENABLE[3])
};

union IC_SDA_STUCK_AT_LOW_TIMEOUT_REG {
	uint32_t 		 all;
	struct IC_SDA_STUCK_AT_LOW_TIMEOUT_BITS 		 bit;
};

struct IC_CLR_SCL_STUCK_DET_BITS {			// bits   description
	uint32_t	CLR_SCL_STUCK_DET:1;			// 0:0   Read this register to clear the SCL_STUCT_AT_LOW interrupt (bit 15) of the IC_RAW_INTR_STAT register.
	uint32_t	rsvd1:31;			// 31:1   reserved
};

union IC_CLR_SCL_STUCK_DET_REG {
	uint32_t 		 all;
	struct IC_CLR_SCL_STUCK_DET_BITS 		 bit;
};

struct IC_SMBUS_CLK_LOW_SEXT_BITS {			// bits   description
	uint32_t	SMBUS_CLK_LOW_SEXT_TIMEOUT:32;			// 31:0   This field is used to detect the Slave Clock Extend timeout (tLOW:SEXT) in master mode extended by the
};

union IC_SMBUS_CLK_LOW_SEXT_REG {
	uint32_t 		 all;
	struct IC_SMBUS_CLK_LOW_SEXT_BITS 		 bit;
};

struct IC_SMBUS_CLK_LOW_MEXT_BITS {			// bits   description
	uint32_t	SMBUS_CLK_LOW_MEXT_TIMEOUT:32;			// 31:0   This field is used to detect the Master extend SMBus clock (SCLK) timeout defined from START-to-ACK,
};

union IC_SMBUS_CLK_LOW_MEXT_REG {
	uint32_t 		 all;
	struct IC_SMBUS_CLK_LOW_MEXT_BITS 		 bit;
};

struct IC_SMBUS_THIGH_MAX_IDLE_COUNT_BITS {			// bits   description
	uint32_t	SMBUS_THIGH_MAX_BUS_IDLE_CNT:16;			// 15:0   This field is used to set the required Bus-Idle time period used when a master has been dynamically added
	uint32_t	rsvd1:16;			// 31:16   reserved
};

union IC_SMBUS_THIGH_MAX_IDLE_COUNT_REG {
	uint32_t 		 all;
	struct IC_SMBUS_THIGH_MAX_IDLE_COUNT_BITS 		 bit;
};

struct IC_SMBUS_INTR_STAT_BITS {			// bits   description
	uint32_t	R_SLV_CLOCK_EXTND_TIMEOUT:1;			// 0:0   Indicates whether the transaction from Slave (i.e from START to STOP) exceeds IC_SMBUS_CLK_LOW_SEXT time.

	uint32_t	R_MST_CLOCK_EXTND_TIMEOUT:1;			// 1:1   Indicates whether the Master device transaction (START-to-ACK, ACK-to-ACK, or ACK-to-STOP) from START
	uint32_t	R_QUICK_CMD_DET:1;			// 2:2   Indicates whether a Quick command has been received on the SMBus interface regardless of whether DW_apb_i2c
	uint32_t	R_HOST_NOTIFY_MST_DET:1;			// 3:3   Indicates whether a Notify ARP Master ARP command has been received.

	uint32_t	R_ARP_PREPARE_CMD_DET:1;			// 4:4   Indicates whether a prepare to ARP command has been received.

	uint32_t	R_ARP_RST_CMD_DET:1;			// 5:5   Indicates whether a General or Directed Reset ARP command has been received.

	uint32_t	R_ARP_GET_UDID_CMD_DET:1;			// 6:6   Indicates whether a Get UDID ARP command has been received.

	uint32_t	R_ARP_ASSGN_ADDR_CMD_DET:1;			// 7:7   Indicates whether an Assign Address ARP command has been received.

	uint32_t	R_SLV_RX_PEC_NACK:1;			// 8:8   Indicates whether a NACK has been sent due to PEC mismatch while working as ARP slave.

	uint32_t	R_SMBUS_SUSPEND_DET:1;			// 9:9   Indicates whether a SMBSUS (ic_smbsus_in_n) signal is driven low by the Host.

	uint32_t	R_SMBUS_ALERT_DET:1;			// 10:10   Indicates whether a SMBALERT (ic_smbalert_in_n) signal is driven low by the slave.

	uint32_t	rsvd1:21;			// 31:11   reserved
};

union IC_SMBUS_INTR_STAT_REG {
	uint32_t 		 all;
	struct IC_SMBUS_INTR_STAT_BITS 		 bit;
};

struct IC_SMBUS_INTR_MASK_BITS {			// bits   description
	uint32_t	M_SLV_CLOCK_EXTND_TIMEOUT:1;			// 0:0   This bit masks the R_SLV_CLOCK_EXTND_TIMEOUT interrupt in IC_SMBUS_INTR_STAT register.

	uint32_t	M_MST_CLOCK_EXTND_TIMEOUT:1;			// 1:1   This bit masks the R_MST_CLOCK_EXTND_TIMEOUT interrupt in IC_SMBUS_INTR_STAT register.

	uint32_t	M_QUICK_CMD_DET:1;			// 2:2   This bit masks the R_QUICK_CMD_DET interrupt in IC_SMBUS_INTR_STAT register.

	uint32_t	M_HOST_NOTIFY_MST_DET:1;			// 3:3   This bit masks the R_HOST_NOTIFY_MST_DET interrupt in IC_SMBUS_INTR_STAT register.

	uint32_t	M_ARP_PREPARE_CMD_DET:1;			// 4:4   This bit masks the R_ARP_PREPARE_CMD_DET interrupt in IC_SMBUS_INTR_STAT register.

	uint32_t	M_ARP_RST_CMD_DET:1;			// 5:5   This bit masks the R_ARP_RST_CMD_DET interrupt in IC_SMBUS_INTR_STAT register.

	uint32_t	M_ARP_GET_UDID_CMD_DET:1;			// 6:6   This bit masks the R_ARP_GET_UDID_CMD_DET interrupt in IC_SMBUS_INTR_STAT register.

	uint32_t	M_ARP_ASSGN_ADDR_CMD_DET:1;			// 7:7   This bit masks the R_ARP_ASSGN_ADDR_CMD_DET interrupt in IC_SMBUS_INTR_STAT register.

	uint32_t	M_SLV_RX_PEC_NACK:1;			// 8:8   This bit masks the R_SLV_RX_PEC_NACK interrupt in IC_SMBUS_INTR_STAT register.

	uint32_t	M_SMBUS_SUSPEND_DET:1;			// 9:9   This bit masks the M_SMBUS_SUSPEND_DET interrupt in IC_SMBUS_INTR_STAT register.

	uint32_t	M_SMBUS_ALERT_DET:1;			// 10:10   This bit masks the R_SMBUS_ALERT_DET interrupt in IC_SMBUS_INTR_STAT register.

	uint32_t	rsvd1:21;			// 31:11   reserved
};

union IC_SMBUS_INTR_MASK_REG {
	uint32_t 		 all;
	struct IC_SMBUS_INTR_MASK_BITS 		 bit;
};

struct IC_SMBUS_RAW_INTR_STAT_BITS {			// bits   description
	uint32_t	SLV_CLOCK_EXTND_TIMEOUT:1;			// 0:0   Indicates whether the transaction from Slave (i.e from START to STOP) exceeds IC_SMBUS_CLK_LOW_SEXT time.

	uint32_t	MST_CLOCK_EXTND_TIMEOUT:1;			// 1:1   Indicates whether the Master device transaction (START-to-ACK, ACK-to-ACK, or ACK-to-STOP) from START
	uint32_t	QUICK_CMD_DET:1;			// 2:2   Indicates whether a Quick command has been received on the SMBus interface regardless of whether DW_apb_i2c
	uint32_t	HOST_NOTIFY_MST_DET:1;			// 3:3   Indicates whether a Notify ARP Master ARP command has been received.

	uint32_t	ARP_PREPARE_CMD_DET:1;			// 4:4   Indicates whether a prepare to ARP command has been received.

	uint32_t	ARP_RST_CMD_DET:1;			// 5:5   Indicates whether a General or Directed Reset ARP command has been received.

	uint32_t	ARP_GET_UDID_CMD_DET:1;			// 6:6   Indicates whether a Get UDID ARP command has been received.

	uint32_t	ARP_ASSGN_ADDR_CMD_DET:1;			// 7:7   Indicates whether an Assign Address ARP command has been received.

	uint32_t	SLV_RX_PEC_NACK:1;			// 8:8   Indicates whether a NACK has been sent due to PEC mismatch while working as ARP slave.

	uint32_t	SMBUS_SUSPEND_DET:1;			// 9:9   Indicates whether a SMBSUS (ic_smbsus_in_n) signal is driven low by the Host.

	uint32_t	SMBUS_ALERT_DET:1;			// 10:10   Indicates whether a SMBALERT (ic_smbalert_in_n) signal is driven low by the slave.

	uint32_t	rsvd1:21;			// 31:11   reserved
};

union IC_SMBUS_RAW_INTR_STAT_REG {
	uint32_t 		 all;
	struct IC_SMBUS_RAW_INTR_STAT_BITS 		 bit;
};

struct IC_CLR_SMBUS_INTR_BITS {			// bits   description
	uint32_t	CLR_SLV_CLOCK_EXTND_TIMEOUT:1;			// 0:0   Write this register bit to clear the SLV_CLOCK_EXTND_TIMEOUT interrupt (bit 0) of the IC_SMBUS_RAW_INTR_STAT
	uint32_t	CLR_MST_CLOCK_EXTND_TIMEOUT:1;			// 1:1   Write this register bit to clear the MST_CLOCK_EXTND_TIMEOUT interrupt (bit 1) of the IC_SMBUS_RAW_INTR_STAT
	uint32_t	CLR_QUICK_CMD_DET:1;			// 2:2   Write this register bit to clear the QUICK_CMD_DET interrupt (bit 2) of the IC_SMBUS_RAW_INTR_STAT register.
	uint32_t	CLR_HOST_NOTIFY_MST_DET:1;			// 3:3   Write this register bit to clear the HOST_NOTIFY_MST_DET interrupt (bit 3) of the IC_SMBUS_RAW_INTR_STAT
	uint32_t	CLR_ARP_PREPARE_CMD_DET:1;			// 4:4   Write this register bit to clear the ARP_PREPARE_CMD_DET interrupt (bit 4) of the IC_SMBUS_RAW_INTR_STAT
	uint32_t	CLR_ARP_RST_CMD_DET:1;			// 5:5   Write this register bit to clear the ARP_RST_CMD_DET interrupt (bit 5) of the IC_SMBUS_RAW_INTR_STAT
	uint32_t	CLR_ARP_GET_UDID_CMD_DET:1;			// 6:6   Write this register bit to clear the ARP_GET_UDID_CMD_DET interrupt (bit 6) of the IC_SMBUS_RAW_INTR_STAT
	uint32_t	CLR_ARP_ASSGN_ADDR_CMD_DET:1;			// 7:7   Write this register bit to clear the ARP_ASSGN_ADDR_CMD_DET interrupt (bit 7) of the IC_SMBUS_RAW_INTR_STAT
	uint32_t	CLR_SLV_RX_PEC_NACK:1;			// 8:8   Write this register bit to clear the SLV_RX_PEC_NACK interrupt (bit 8) of the IC_SMBUS_RAW_INTR_STAT
	uint32_t	CLR_SMBUS_SUSPEND_DET:1;			// 9:9   Write this register bit to clear the SMBUS_SUSPEND_DET interrupt (bit 9) of the IC_SMBUS_RAW_INTR_STAT
	uint32_t	CLR_SMBUS_ALERT_DET:1;			// 10:10   Write this register bit to clear the SMBUS_ALERT_DET interrupt (bit 10) of the IC_SMBUS_RAW_INTR_STAT
	uint32_t	rsvd1:21;			// 31:11   reserved
};

union IC_CLR_SMBUS_INTR_REG {
	uint32_t 		 all;
	struct IC_CLR_SMBUS_INTR_BITS 		 bit;
};

struct IC_SMBUS_UDID_LSB_BITS {			// bits   description
	uint32_t	SMBUS_UDID_LSB:32;			// 31:0   This field is used to store the LSB 32 bit value of slave unique device identifier used in Address Resolution
};

union IC_SMBUS_UDID_LSB_REG {
	uint32_t 		 all;
	struct IC_SMBUS_UDID_LSB_BITS 		 bit;
};

struct IC_SAR2_BITS {			// bits   description
	uint32_t	IC_SAR2:10;			// 9:0   The IC_SAR2 holds the slave address 2 when the I2C is operating as a slave. For 7-bit addressing, only
	uint32_t	rsvd1:22;			// 31:10   reserved
};

union IC_SAR2_REG {
	uint32_t 		 all;
	struct IC_SAR2_BITS 		 bit;
};

struct IC_CLR_WR_REQ_BITS {			// bits   description
	uint32_t	CLR_WR_REQ:1;			// 0:0   Read this register to clear the WR_REQ interrupt (bit 15) of the IC_RAW_INTR_STAT register.
	uint32_t	rsvd1:31;			// 31:1   reserved
};

union IC_CLR_WR_REQ_REG {
	uint32_t 		 all;
	struct IC_CLR_WR_REQ_BITS 		 bit;
};

struct IC_CLR_SLV_ADDR_TAG_BITS {			// bits   description
	uint32_t	CLR_SLV_ADDR_TAG:1;			// 0:0   Read this register to clear all SLV_ADDRx_TAG (Where x is 1 through IC_NUM_SARS) interrupts (bit 16 ...(16+IC_NUM_SARS-1))
	uint32_t	rsvd1:31;			// 31:1   reserved
};

union IC_CLR_SLV_ADDR_TAG_REG {
	uint32_t 		 all;
	struct IC_CLR_SLV_ADDR_TAG_BITS 		 bit;
};


// I2C_PMBUS_SMBUS Register Definitions:

struct I2C_REGS {
	union  IC_CON_REG			IC_CON;
	union  IC_TAR_REG			IC_TAR;
	union  IC_SAR_REG			IC_SAR;
	uint32_t 						rsvd1; 		 // reserved
	union  IC_DATA_CMD_REG			IC_DATA_CMD;
	union  IC_SS_SCL_HCNT_REG			IC_SS_SCL_HCNT;
	union  IC_SS_SCL_LCNT_REG			IC_SS_SCL_LCNT;
	union  IC_FS_SCL_HCNT_REG			IC_FS_SCL_HCNT;
	union  IC_FS_SCL_LCNT_REG			IC_FS_SCL_LCNT;
	uint32_t 						rsvd2[2]; 		 // reserved
	union  IC_INTR_STAT_REG			IC_INTR_STAT;
	union  IC_INTR_MASK_REG			IC_INTR_MASK;
	union  IC_RAW_INTR_STAT_REG			IC_RAW_INTR_STAT;
	union  IC_RX_TL_REG			IC_RX_TL;
	union  IC_TX_TL_REG			IC_TX_TL;
	union  IC_CLR_INTR_REG			IC_CLR_INTR;
	union  IC_CLR_RX_UNDER_REG			IC_CLR_RX_UNDER;
	union  IC_CLR_RX_OVER_REG			IC_CLR_RX_OVER;
	union  IC_CLR_TX_OVER_REG			IC_CLR_TX_OVER;
	union  IC_CLR_RD_REQ_REG			IC_CLR_RD_REQ;
	union  IC_CLR_TX_ABRT_REG			IC_CLR_TX_ABRT;
	union  IC_CLR_RX_DONE_REG			IC_CLR_RX_DONE;
	union  IC_CLR_ACTIVITY_REG			IC_CLR_ACTIVITY;
	union  IC_CLR_STOP_DET_REG			IC_CLR_STOP_DET;
	union  IC_CLR_START_DET_REG			IC_CLR_START_DET;
	union  IC_CLR_GEN_CALL_REG			IC_CLR_GEN_CALL;
	union  IC_ENABLE_REG			IC_ENABLE;
	union  IC_STATUS_REG			IC_STATUS;
	union  IC_TXFLR_REG			IC_TXFLR;
	union  IC_RXFLR_REG			IC_RXFLR;
	union  IC_SDA_HOLD_REG			IC_SDA_HOLD;
	union  IC_TX_ABRT_SOURCE_REG			IC_TX_ABRT_SOURCE;
	uint32_t 						rsvd3; 		 // reserved
	union  IC_DMA_CR_REG			IC_DMA_CR;
	union  IC_DMA_TDLR_REG			IC_DMA_TDLR;
	union  IC_DMA_RDLR_REG			IC_DMA_RDLR;
	union  IC_SDA_SETUP_REG			IC_SDA_SETUP;
	union  IC_ACK_GENERAL_CALL_REG			IC_ACK_GENERAL_CALL;
	union  IC_ENABLE_STATUS_REG			IC_ENABLE_STATUS;
	union  IC_FS_SPKLEN_REG			IC_FS_SPKLEN;
	uint32_t 						rsvd4; 		 // reserved
	union  IC_CLR_RESTART_DET_REG			IC_CLR_RESTART_DET;
	union  IC_SCL_STUCK_AT_LOW_TIMEOUT_REG			IC_SCL_STUCK_AT_LOW_TIMEOUT;
	union  IC_SDA_STUCK_AT_LOW_TIMEOUT_REG			IC_SDA_STUCK_AT_LOW_TIMEOUT;
	union  IC_CLR_SCL_STUCK_DET_REG			IC_CLR_SCL_STUCK_DET;
	uint32_t 						rsvd5; 		 // reserved
	union  IC_SMBUS_CLK_LOW_SEXT_REG			IC_SMBUS_CLK_LOW_SEXT;
	union  IC_SMBUS_CLK_LOW_MEXT_REG			IC_SMBUS_CLK_LOW_MEXT;
	union  IC_SMBUS_THIGH_MAX_IDLE_COUNT_REG			IC_SMBUS_THIGH_MAX_IDLE_COUNT;
	union  IC_SMBUS_INTR_STAT_REG			IC_SMBUS_INTR_STAT;
	union  IC_SMBUS_INTR_MASK_REG			IC_SMBUS_INTR_MASK;
	union  IC_SMBUS_RAW_INTR_STAT_REG			IC_SMBUS_RAW_INTR_STAT;
	union  IC_CLR_SMBUS_INTR_REG			IC_CLR_SMBUS_INTR;
	uint32_t 						rsvd6; 		 // reserved
	union  IC_SMBUS_UDID_LSB_REG			IC_SMBUS_UDID_LSB;
	uint32_t 						rsvd7[8]; 		 // reserved
	union  IC_SAR2_REG			IC_SAR2;
	uint32_t 						rsvd8[6]; 		 // reserved
	union  IC_CLR_WR_REQ_REG			IC_CLR_WR_REQ;
	union  IC_CLR_SLV_ADDR_TAG_REG			IC_CLR_SLV_ADDR_TAG;
};

extern volatile struct I2C_REGS I2caRegs;
extern volatile struct I2C_REGS I2cbRegs;



#ifdef __cplusplus
}
#endif /* extern "C" */


#endif  // end of REGS_I2C_PMBUS_SMBUS_H definition
