/*===========================================================================
 * KronConverter — Type Conversion Implementations
 * N=12 types → N*(N-1) = 132 functions
 *===========================================================================*/

#include "kronconverter.h"

/*===========================================================================
 * FROM BOOL
 * true → 1, false → 0
 *===========================================================================*/
uint8_t  KRON_BOOL_TO_BYTE  (bool v) { return (uint8_t)v;          }
uint16_t KRON_BOOL_TO_WORD  (bool v) { return (uint16_t)v;         }
uint32_t KRON_BOOL_TO_DWORD (bool v) { return (uint32_t)v;         }
uint8_t  KRON_BOOL_TO_UINT8 (bool v) { return (uint8_t)v;          }
uint16_t KRON_BOOL_TO_UINT16(bool v) { return (uint16_t)v;         }
uint32_t KRON_BOOL_TO_UINT32(bool v) { return (uint32_t)v;         }
int8_t   KRON_BOOL_TO_INT8  (bool v) { return (int8_t)v;           }
int16_t  KRON_BOOL_TO_INT16 (bool v) { return (int16_t)v;          }
int32_t  KRON_BOOL_TO_INT32 (bool v) { return (int32_t)v;          }
float    KRON_BOOL_TO_REAL  (bool v) { return v ? 1.0f : 0.0f;     }
double   KRON_BOOL_TO_LREAL (bool v) { return v ? 1.0  : 0.0;      }

/*===========================================================================
 * FROM BYTE
 * → BOOL  : 0 → false, nonzero → true
 * → WORD  : zero-extend
 * → DWORD : zero-extend
 * → UINT8 : bitwise identity (same underlying type)
 * → wider : zero-extend
 * → INT8  : bitwise reinterpret (two's complement); values > 127 become negative
 * → REAL  : exact (uint8 fits in float32 mantissa)
 * → LREAL : exact (uint8 fits in float64 mantissa)
 *===========================================================================*/
bool     KRON_BYTE_TO_BOOL  (uint8_t v) { return v != 0;            }
uint16_t KRON_BYTE_TO_WORD  (uint8_t v) { return (uint16_t)v;       }
uint32_t KRON_BYTE_TO_DWORD (uint8_t v) { return (uint32_t)v;       }
uint8_t  KRON_BYTE_TO_UINT8 (uint8_t v) { return v;                 }
uint16_t KRON_BYTE_TO_UINT16(uint8_t v) { return (uint16_t)v;       }
uint32_t KRON_BYTE_TO_UINT32(uint8_t v) { return (uint32_t)v;       }
int8_t   KRON_BYTE_TO_INT8  (uint8_t v) { return (int8_t)v;         }
int16_t  KRON_BYTE_TO_INT16 (uint8_t v) { return (int16_t)v;        }
int32_t  KRON_BYTE_TO_INT32 (uint8_t v) { return (int32_t)v;        }
float    KRON_BYTE_TO_REAL  (uint8_t v) { return (float)v;          }
double   KRON_BYTE_TO_LREAL (uint8_t v) { return (double)v;         }

/*===========================================================================
 * FROM WORD
 * → BOOL   : 0 → false, nonzero → true
 * → BYTE   : keep low byte
 * → DWORD  : zero-extend
 * → UINT8  : keep low byte
 * → UINT16 : bitwise identity
 * → UINT32 : zero-extend
 * → INT8   : keep low byte, reinterpret as signed
 * → INT16  : bitwise reinterpret; values > 32767 become negative
 * → INT32  : zero-extend (always non-negative)
 * → REAL   : exact (uint16 fits in float32 mantissa)
 * → LREAL  : exact (uint16 fits in float64 mantissa)
 *===========================================================================*/
bool     KRON_WORD_TO_BOOL  (uint16_t v) { return v != 0;           }
uint8_t  KRON_WORD_TO_BYTE  (uint16_t v) { return (uint8_t)v;       }
uint32_t KRON_WORD_TO_DWORD (uint16_t v) { return (uint32_t)v;      }
uint8_t  KRON_WORD_TO_UINT8 (uint16_t v) { return (uint8_t)v;       }
uint16_t KRON_WORD_TO_UINT16(uint16_t v) { return v;                }
uint32_t KRON_WORD_TO_UINT32(uint16_t v) { return (uint32_t)v;      }
int8_t   KRON_WORD_TO_INT8  (uint16_t v) { return (int8_t)v;        }
int16_t  KRON_WORD_TO_INT16 (uint16_t v) { return (int16_t)v;       }
int32_t  KRON_WORD_TO_INT32 (uint16_t v) { return (int32_t)v;       }
float    KRON_WORD_TO_REAL  (uint16_t v) { return (float)v;         }
double   KRON_WORD_TO_LREAL (uint16_t v) { return (double)v;        }

/*===========================================================================
 * FROM DWORD
 * → BOOL   : 0 → false, nonzero → true
 * → BYTE   : keep low byte
 * → WORD   : keep low 2 bytes (low word)
 * → UINT8  : keep low byte
 * → UINT16 : keep low 2 bytes
 * → UINT32 : bitwise identity
 * → INT8   : keep low byte, reinterpret as signed
 * → INT16  : keep low 2 bytes, reinterpret as signed
 * → INT32  : bitwise reinterpret; values > 2147483647 become negative
 * → REAL   : may lose ~1 ULP for values > 2^24
 * → LREAL  : exact (uint32 fits in float64 mantissa)
 *===========================================================================*/
bool     KRON_DWORD_TO_BOOL  (uint32_t v) { return v != 0;          }
uint8_t  KRON_DWORD_TO_BYTE  (uint32_t v) { return (uint8_t)v;      }
uint16_t KRON_DWORD_TO_WORD  (uint32_t v) { return (uint16_t)v;     }
uint8_t  KRON_DWORD_TO_UINT8 (uint32_t v) { return (uint8_t)v;      }
uint16_t KRON_DWORD_TO_UINT16(uint32_t v) { return (uint16_t)v;     }
uint32_t KRON_DWORD_TO_UINT32(uint32_t v) { return v;               }
int8_t   KRON_DWORD_TO_INT8  (uint32_t v) { return (int8_t)v;       }
int16_t  KRON_DWORD_TO_INT16 (uint32_t v) { return (int16_t)v;      }
int32_t  KRON_DWORD_TO_INT32 (uint32_t v) { return (int32_t)v;      }
float    KRON_DWORD_TO_REAL  (uint32_t v) { return (float)v;        }
double   KRON_DWORD_TO_LREAL (uint32_t v) { return (double)v;       }

/*===========================================================================
 * FROM UINT8
 * → BOOL   : 0 → false, nonzero → true
 * → BYTE   : bitwise identity (same underlying type)
 * → WORD   : zero-extend
 * → DWORD  : zero-extend
 * → wider  : zero-extend
 * → INT8   : bitwise reinterpret (two's complement); values > 127 become negative
 * → REAL   : exact (uint8 fits in float32 mantissa)
 * → LREAL  : exact (uint8 fits in float64 mantissa)
 *===========================================================================*/
bool     KRON_UINT8_TO_BOOL  (uint8_t v) { return v != 0;           }
uint8_t  KRON_UINT8_TO_BYTE  (uint8_t v) { return v;                }
uint16_t KRON_UINT8_TO_WORD  (uint8_t v) { return (uint16_t)v;      }
uint32_t KRON_UINT8_TO_DWORD (uint8_t v) { return (uint32_t)v;      }
uint16_t KRON_UINT8_TO_UINT16(uint8_t v) { return (uint16_t)v;      }
uint32_t KRON_UINT8_TO_UINT32(uint8_t v) { return (uint32_t)v;      }
int8_t   KRON_UINT8_TO_INT8  (uint8_t v) { return (int8_t)v;        }
int16_t  KRON_UINT8_TO_INT16 (uint8_t v) { return (int16_t)v;       }
int32_t  KRON_UINT8_TO_INT32 (uint8_t v) { return (int32_t)v;       }
float    KRON_UINT8_TO_REAL  (uint8_t v) { return (float)v;         }
double   KRON_UINT8_TO_LREAL (uint8_t v) { return (double)v;        }

/*===========================================================================
 * FROM UINT16
 * → BOOL   : 0 → false, nonzero → true
 * → BYTE   : keep low byte (truncate)
 * → WORD   : bitwise identity
 * → DWORD  : zero-extend
 * → UINT8  : keep low byte (truncate)
 * → UINT32 : zero-extend
 * → INT8   : keep low byte, reinterpret as signed
 * → INT16  : bitwise reinterpret; values > 32767 become negative
 * → INT32  : zero-extend (always non-negative)
 * → REAL   : exact (uint16 fits in float32 mantissa)
 * → LREAL  : exact (uint16 fits in float64 mantissa)
 *===========================================================================*/
bool     KRON_UINT16_TO_BOOL  (uint16_t v) { return v != 0;         }
uint8_t  KRON_UINT16_TO_BYTE  (uint16_t v) { return (uint8_t)v;     }
uint16_t KRON_UINT16_TO_WORD  (uint16_t v) { return v;              }
uint32_t KRON_UINT16_TO_DWORD (uint16_t v) { return (uint32_t)v;    }
uint8_t  KRON_UINT16_TO_UINT8 (uint16_t v) { return (uint8_t)v;     }
uint32_t KRON_UINT16_TO_UINT32(uint16_t v) { return (uint32_t)v;    }
int8_t   KRON_UINT16_TO_INT8  (uint16_t v) { return (int8_t)v;      }
int16_t  KRON_UINT16_TO_INT16 (uint16_t v) { return (int16_t)v;     }
int32_t  KRON_UINT16_TO_INT32 (uint16_t v) { return (int32_t)v;     }
float    KRON_UINT16_TO_REAL  (uint16_t v) { return (float)v;       }
double   KRON_UINT16_TO_LREAL (uint16_t v) { return (double)v;      }

/*===========================================================================
 * FROM UINT32
 * → BOOL   : 0 → false, nonzero → true
 * → BYTE   : keep low byte
 * → WORD   : keep low 2 bytes
 * → DWORD  : bitwise identity
 * → UINT8  : keep low byte
 * → UINT16 : keep low 2 bytes
 * → INT8   : keep low byte, reinterpret as signed
 * → INT16  : keep low 2 bytes, reinterpret as signed
 * → INT32  : bitwise reinterpret; values > 2147483647 become negative
 * → REAL   : may lose ~1 ULP for values > 2^24
 * → LREAL  : exact (uint32 fits in float64 mantissa)
 *===========================================================================*/
bool     KRON_UINT32_TO_BOOL  (uint32_t v) { return v != 0;         }
uint8_t  KRON_UINT32_TO_BYTE  (uint32_t v) { return (uint8_t)v;     }
uint16_t KRON_UINT32_TO_WORD  (uint32_t v) { return (uint16_t)v;    }
uint32_t KRON_UINT32_TO_DWORD (uint32_t v) { return v;              }
uint8_t  KRON_UINT32_TO_UINT8 (uint32_t v) { return (uint8_t)v;     }
uint16_t KRON_UINT32_TO_UINT16(uint32_t v) { return (uint16_t)v;    }
int8_t   KRON_UINT32_TO_INT8  (uint32_t v) { return (int8_t)v;      }
int16_t  KRON_UINT32_TO_INT16 (uint32_t v) { return (int16_t)v;     }
int32_t  KRON_UINT32_TO_INT32 (uint32_t v) { return (int32_t)v;     }
float    KRON_UINT32_TO_REAL  (uint32_t v) { return (float)v;       }
double   KRON_UINT32_TO_LREAL (uint32_t v) { return (double)v;      }

/*===========================================================================
 * FROM INT8
 * → BOOL   : 0 → false, nonzero (incl. negative) → true
 * → BYTE   : bitwise reinterpret as uint8_t
 * → WORD   : sign-extend to int16, reinterpret as uint16
 * → DWORD  : sign-extend to int32, reinterpret as uint32
 * → UINT8  : bitwise reinterpret; negative values wrap (e.g. -1 → 255)
 * → UINT16 : sign-extend to int16, reinterpret as uint16
 * → UINT32 : sign-extend to int32, reinterpret as uint32
 * → INT16  : sign-extend (always exact)
 * → INT32  : sign-extend (always exact)
 * → REAL   : exact
 * → LREAL  : exact
 *===========================================================================*/
bool     KRON_INT8_TO_BOOL  (int8_t v) { return v != 0;                  }
uint8_t  KRON_INT8_TO_BYTE  (int8_t v) { return (uint8_t)v;              }
uint16_t KRON_INT8_TO_WORD  (int8_t v) { return (uint16_t)(int16_t)v;    }
uint32_t KRON_INT8_TO_DWORD (int8_t v) { return (uint32_t)(int32_t)v;    }
uint8_t  KRON_INT8_TO_UINT8 (int8_t v) { return (uint8_t)v;              }
uint16_t KRON_INT8_TO_UINT16(int8_t v) { return (uint16_t)(int16_t)v;    }
uint32_t KRON_INT8_TO_UINT32(int8_t v) { return (uint32_t)(int32_t)v;    }
int16_t  KRON_INT8_TO_INT16 (int8_t v) { return (int16_t)v;              }
int32_t  KRON_INT8_TO_INT32 (int8_t v) { return (int32_t)v;              }
float    KRON_INT8_TO_REAL  (int8_t v) { return (float)v;                }
double   KRON_INT8_TO_LREAL (int8_t v) { return (double)v;               }

/*===========================================================================
 * FROM INT16
 * → BOOL   : 0 → false, nonzero (incl. negative) → true
 * → BYTE   : keep low byte
 * → WORD   : bitwise reinterpret as uint16
 * → DWORD  : sign-extend to int32, reinterpret as uint32
 * → UINT8  : keep low byte
 * → UINT16 : bitwise reinterpret; negative values wrap
 * → UINT32 : sign-extend to int32, reinterpret as uint32
 * → INT8   : truncate to low byte, reinterpret as signed
 * → INT32  : sign-extend (always exact)
 * → REAL   : exact
 * → LREAL  : exact
 *===========================================================================*/
bool     KRON_INT16_TO_BOOL  (int16_t v) { return v != 0;               }
uint8_t  KRON_INT16_TO_BYTE  (int16_t v) { return (uint8_t)v;           }
uint16_t KRON_INT16_TO_WORD  (int16_t v) { return (uint16_t)v;          }
uint32_t KRON_INT16_TO_DWORD (int16_t v) { return (uint32_t)(int32_t)v; }
uint8_t  KRON_INT16_TO_UINT8 (int16_t v) { return (uint8_t)v;           }
uint16_t KRON_INT16_TO_UINT16(int16_t v) { return (uint16_t)v;          }
uint32_t KRON_INT16_TO_UINT32(int16_t v) { return (uint32_t)(int32_t)v; }
int8_t   KRON_INT16_TO_INT8  (int16_t v) { return (int8_t)v;            }
int32_t  KRON_INT16_TO_INT32 (int16_t v) { return (int32_t)v;           }
float    KRON_INT16_TO_REAL  (int16_t v) { return (float)v;             }
double   KRON_INT16_TO_LREAL (int16_t v) { return (double)v;            }

/*===========================================================================
 * FROM INT32
 * → BOOL   : 0 → false, nonzero (incl. negative) → true
 * → BYTE   : keep low byte
 * → WORD   : keep low 2 bytes
 * → DWORD  : bitwise reinterpret as uint32
 * → UINT8  : keep low byte
 * → UINT16 : keep low 2 bytes
 * → UINT32 : bitwise reinterpret; negative values wrap
 * → INT8   : truncate to low byte
 * → INT16  : truncate to low 2 bytes
 * → REAL   : may lose ~1 ULP for |v| > 2^24 (~16 million)
 * → LREAL  : exact (int32 fits in float64 mantissa)
 *===========================================================================*/
bool     KRON_INT32_TO_BOOL  (int32_t v) { return v != 0;           }
uint8_t  KRON_INT32_TO_BYTE  (int32_t v) { return (uint8_t)v;       }
uint16_t KRON_INT32_TO_WORD  (int32_t v) { return (uint16_t)v;      }
uint32_t KRON_INT32_TO_DWORD (int32_t v) { return (uint32_t)v;      }
uint8_t  KRON_INT32_TO_UINT8 (int32_t v) { return (uint8_t)v;       }
uint16_t KRON_INT32_TO_UINT16(int32_t v) { return (uint16_t)v;      }
uint32_t KRON_INT32_TO_UINT32(int32_t v) { return (uint32_t)v;      }
int8_t   KRON_INT32_TO_INT8  (int32_t v) { return (int8_t)v;        }
int16_t  KRON_INT32_TO_INT16 (int32_t v) { return (int16_t)v;       }
float    KRON_INT32_TO_REAL  (int32_t v) { return (float)v;         }
double   KRON_INT32_TO_LREAL (int32_t v) { return (double)v;        }

/*===========================================================================
 * FROM REAL (float)
 * → BOOL   : 0.0f → false, any nonzero (incl. negative, NaN) → true
 *            Note: -0.0f == 0.0f in IEEE 754, so -0.0f → false
 * → BYTE/WORD/DWORD/UINT* : truncation toward zero; negative → 0 on ARM
 * → INT*   : truncation toward zero; out-of-range → implementation-defined
 * → LREAL  : widening cast (always exact value)
 *===========================================================================*/
bool     KRON_REAL_TO_BOOL  (float v) { return v != 0.0f;        }
uint8_t  KRON_REAL_TO_BYTE  (float v) { return (uint8_t)v;       }
uint16_t KRON_REAL_TO_WORD  (float v) { return (uint16_t)v;      }
uint32_t KRON_REAL_TO_DWORD (float v) { return (uint32_t)v;      }
uint8_t  KRON_REAL_TO_UINT8 (float v) { return (uint8_t)v;       }
uint16_t KRON_REAL_TO_UINT16(float v) { return (uint16_t)v;      }
uint32_t KRON_REAL_TO_UINT32(float v) { return (uint32_t)v;      }
int8_t   KRON_REAL_TO_INT8  (float v) { return (int8_t)v;        }
int16_t  KRON_REAL_TO_INT16 (float v) { return (int16_t)v;       }
int32_t  KRON_REAL_TO_INT32 (float v) { return (int32_t)v;       }
double   KRON_REAL_TO_LREAL (float v) { return (double)v;        }

/*===========================================================================
 * FROM LREAL (double)
 * → BOOL   : 0.0 → false, any nonzero (incl. negative, NaN) → true
 *            Note: -0.0 == 0.0 in IEEE 754, so -0.0 → false
 * → BYTE/WORD/DWORD/UINT* : truncation toward zero; negative → 0 on ARM
 * → INT*   : truncation toward zero; out-of-range → implementation-defined
 * → REAL   : narrowing cast; may lose precision for large or subnormal values
 *===========================================================================*/
bool     KRON_LREAL_TO_BOOL  (double v) { return v != 0.0;         }
uint8_t  KRON_LREAL_TO_BYTE  (double v) { return (uint8_t)v;       }
uint16_t KRON_LREAL_TO_WORD  (double v) { return (uint16_t)v;      }
uint32_t KRON_LREAL_TO_DWORD (double v) { return (uint32_t)v;      }
uint8_t  KRON_LREAL_TO_UINT8 (double v) { return (uint8_t)v;       }
uint16_t KRON_LREAL_TO_UINT16(double v) { return (uint16_t)v;      }
uint32_t KRON_LREAL_TO_UINT32(double v) { return (uint32_t)v;      }
int8_t   KRON_LREAL_TO_INT8  (double v) { return (int8_t)v;        }
int16_t  KRON_LREAL_TO_INT16 (double v) { return (int16_t)v;       }
int32_t  KRON_LREAL_TO_INT32 (double v) { return (int32_t)v;       }
float    KRON_LREAL_TO_REAL  (double v) { return (float)v;         }
