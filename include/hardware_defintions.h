#define PERIPH_BASE 		0x40000000UL
#define AHB1_OFFSET			0x00020000UL
#define AHB1_BASE			(PERIPH_BASE + AHB1_OFFSET)

#define GPIOA_OFFSET		0x0000U // 0's will only change the hex value if they are removed after the active bits
#define GPIOA_BASE	 		(AHB1_BASE + GPIOA_OFFSET)

#define RCC_OFFSET			0x3800U
#define RCC_BASE			(AHB1_BASE + RCC_OFFSET)

#define RCC_AHB1EN_R_OFFSET	0x0030U
#define RCC_AHBEN_R			(*(volatile unsigned int*) (RCC_BASE + RCC_AHB1EN_R_OFFSET))

#define MODE_R_OFFSET		0x0000U
#define GPIOA_MODE_R		(*(volatile unsigned int*) (GPIOA_BASE + MODE_R_OFFSET))

#define GPIOAEN				(1U << 0) // Set the GPIOAEN bit to 1 in the RCCAHB1EN_R register

#define GPIOX_ODR_OFFSET	0x0014UL
#define GPIOA_OD_R			(*(volatile unsigned int*) (GPIOA_BASE + GPIOX_ODR_OFFSET))

#define PIN5_HIGH			(1U << 5)