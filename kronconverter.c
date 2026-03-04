/*===========================================================================
 * KronConverter — Type Conversion Implementations
 * N=8 types → N*(N-1) = 56 functions
 *===========================================================================*/

#include "kronconverter.h"

/*===========================================================================
 * FROM BOOL
 * true → 1, false → 0
 *===========================================================================*/
uint8_t  KRON_BOOL_TO_UINT8 (bool v) { return (uint8_t)v;  }
uint16_t KRON_BOOL_TO_UINT16(bool v) { return (uint16_t)v; }
uint32_t KRON_BOOL_TO_UINT32(bool v) { return (uint32_t)v; }
int8_t   KRON_BOOL_TO_INT8  (bool v) { return (int8_t)v;   }
int16_t  KRON_BOOL_TO_INT16 (bool v) { return (int16_t)v;  }
int32_t  KRON_BOOL_TO_INT32 (bool v) { return (int32_t)v;  }
float    KRON_BOOL_TO_REAL  (bool v) { return v ? 1.0f : 0.0f; }

/*===========================================================================
 * FROM UINT8
 * → BOOL  : 0 → false, nonzero → true
 * → wider : zero-extend
 * → INT8  : bitwise reinterpret (two's complement); values > 127 become negative
 * → REAL  : exact (uint8 fits in float32 mantissa)
 *===========================================================================*/
bool     KRON_UINT8_TO_BOOL  (uint8_t v) { return v != 0;          }
uint16_t KRON_UINT8_TO_UINT16(uint8_t v) { return (uint16_t)v;     }
uint32_t KRON_UINT8_TO_UINT32(uint8_t v) { return (uint32_t)v;     }
int8_t   KRON_UINT8_TO_INT8  (uint8_t v) { return (int8_t)v;       }
int16_t  KRON_UINT8_TO_INT16 (uint8_t v) { return (int16_t)v;      }
int32_t  KRON_UINT8_TO_INT32 (uint8_t v) { return (int32_t)v;      }
float    KRON_UINT8_TO_REAL  (uint8_t v) { return (float)v;        }

/*===========================================================================
 * FROM UINT16
 * → BOOL   : 0 → false, nonzero → true
 * → UINT8  : keep low byte (truncate)
 * → UINT32 : zero-extend
 * → INT8   : keep low byte, reinterpret as signed
 * → INT16  : bitwise reinterpret; values > 32767 become negative
 * → INT32  : zero-extend (always non-negative)
 * → REAL   : exact (uint16 fits in float32 mantissa)
 *===========================================================================*/
bool     KRON_UINT16_TO_BOOL  (uint16_t v) { return v != 0;         }
uint8_t  KRON_UINT16_TO_UINT8 (uint16_t v) { return (uint8_t)v;     }
uint32_t KRON_UINT16_TO_UINT32(uint16_t v) { return (uint32_t)v;    }
int8_t   KRON_UINT16_TO_INT8  (uint16_t v) { return (int8_t)v;      }
int16_t  KRON_UINT16_TO_INT16 (uint16_t v) { return (int16_t)v;     }
int32_t  KRON_UINT16_TO_INT32 (uint16_t v) { return (int32_t)v;     }
float    KRON_UINT16_TO_REAL  (uint16_t v) { return (float)v;       }

/*===========================================================================
 * FROM UINT32
 * → BOOL   : 0 → false, nonzero → true
 * → UINT8  : keep low byte
 * → UINT16 : keep low 2 bytes
 * → INT8   : keep low byte, reinterpret as signed
 * → INT16  : keep low 2 bytes, reinterpret as signed
 * → INT32  : bitwise reinterpret; values > 2147483647 become negative
 * → REAL   : may lose ~1 ULP for values > 2^24
 *===========================================================================*/
bool     KRON_UINT32_TO_BOOL  (uint32_t v) { return v != 0;         }
uint8_t  KRON_UINT32_TO_UINT8 (uint32_t v) { return (uint8_t)v;     }
uint16_t KRON_UINT32_TO_UINT16(uint32_t v) { return (uint16_t)v;    }
int8_t   KRON_UINT32_TO_INT8  (uint32_t v) { return (int8_t)v;      }
int16_t  KRON_UINT32_TO_INT16 (uint32_t v) { return (int16_t)v;     }
int32_t  KRON_UINT32_TO_INT32 (uint32_t v) { return (int32_t)v;     }
float    KRON_UINT32_TO_REAL  (uint32_t v) { return (float)v;       }

/*===========================================================================
 * FROM INT8
 * → BOOL   : 0 → false, nonzero (incl. negative) → true
 * → UINT8  : bitwise reinterpret; negative values wrap (e.g. -1 → 255)
 * → UINT16 : sign-extend to int16 then reinterpret as uint16
 * → UINT32 : sign-extend to int32 then reinterpret as uint32
 * → INT16  : sign-extend (always exact)
 * → INT32  : sign-extend (always exact)
 * → REAL   : exact
 *===========================================================================*/
bool     KRON_INT8_TO_BOOL  (int8_t v) { return v != 0;            }
uint8_t  KRON_INT8_TO_UINT8 (int8_t v) { return (uint8_t)v;        }
uint16_t KRON_INT8_TO_UINT16(int8_t v) { return (uint16_t)(int16_t)v; }
uint32_t KRON_INT8_TO_UINT32(int8_t v) { return (uint32_t)(int32_t)v; }
int16_t  KRON_INT8_TO_INT16 (int8_t v) { return (int16_t)v;        }
int32_t  KRON_INT8_TO_INT32 (int8_t v) { return (int32_t)v;        }
float    KRON_INT8_TO_REAL  (int8_t v) { return (float)v;          }

/*===========================================================================
 * FROM INT16
 * → BOOL   : 0 → false, nonzero (incl. negative) → true
 * → UINT8  : keep low byte
 * → UINT16 : bitwise reinterpret; negative values wrap
 * → UINT32 : sign-extend to int32 then reinterpret as uint32
 * → INT8   : truncate to low byte, reinterpret as signed
 * → INT32  : sign-extend (always exact)
 * → REAL   : exact
 *===========================================================================*/
bool     KRON_INT16_TO_BOOL  (int16_t v) { return v != 0;              }
uint8_t  KRON_INT16_TO_UINT8 (int16_t v) { return (uint8_t)v;          }
uint16_t KRON_INT16_TO_UINT16(int16_t v) { return (uint16_t)v;         }
uint32_t KRON_INT16_TO_UINT32(int16_t v) { return (uint32_t)(int32_t)v; }
int8_t   KRON_INT16_TO_INT8  (int16_t v) { return (int8_t)v;           }
int32_t  KRON_INT16_TO_INT32 (int16_t v) { return (int32_t)v;          }
float    KRON_INT16_TO_REAL  (int16_t v) { return (float)v;            }

/*===========================================================================
 * FROM INT32
 * → BOOL   : 0 → false, nonzero (incl. negative) → true
 * → UINT8  : keep low byte
 * → UINT16 : keep low 2 bytes
 * → UINT32 : bitwise reinterpret; negative values wrap
 * → INT8   : truncate to low byte
 * → INT16  : truncate to low 2 bytes
 * → REAL   : may lose ~1 ULP for |v| > 2^24 (~16 million)
 *===========================================================================*/
bool     KRON_INT32_TO_BOOL  (int32_t v) { return v != 0;          }
uint8_t  KRON_INT32_TO_UINT8 (int32_t v) { return (uint8_t)v;      }
uint16_t KRON_INT32_TO_UINT16(int32_t v) { return (uint16_t)v;     }
uint32_t KRON_INT32_TO_UINT32(int32_t v) { return (uint32_t)v;     }
int8_t   KRON_INT32_TO_INT8  (int32_t v) { return (int8_t)v;       }
int16_t  KRON_INT32_TO_INT16 (int32_t v) { return (int16_t)v;      }
float    KRON_INT32_TO_REAL  (int32_t v) { return (float)v;        }

/*===========================================================================
 * FROM REAL (float)
 * → BOOL   : 0.0f → false, any nonzero (incl. negative, NaN) → true
 *            Note: -0.0f == 0.0f in IEEE 754, so -0.0f → false
 * → INT*   : truncation toward zero (C standard cast behavior)
 *            Out-of-range values produce implementation-defined result on ARM
 * → UINT*  : truncation toward zero; negative floats produce 0 on ARM
 *===========================================================================*/
bool     KRON_REAL_TO_BOOL  (float v) { return v != 0.0f;       }
uint8_t  KRON_REAL_TO_UINT8 (float v) { return (uint8_t)v;      }
uint16_t KRON_REAL_TO_UINT16(float v) { return (uint16_t)v;     }
uint32_t KRON_REAL_TO_UINT32(float v) { return (uint32_t)v;     }
int8_t   KRON_REAL_TO_INT8  (float v) { return (int8_t)v;       }
int16_t  KRON_REAL_TO_INT16 (float v) { return (int16_t)v;      }
int32_t  KRON_REAL_TO_INT32 (float v) { return (int32_t)v;      }
