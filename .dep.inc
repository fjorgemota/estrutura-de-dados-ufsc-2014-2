# This code depends on make tool being used
FILES}))
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
DEPFILES=$(wildcard $(addsuffix .d, ${OBJECTFILES}))
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
