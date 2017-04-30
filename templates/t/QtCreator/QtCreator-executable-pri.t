%########################################################################
%# Copyright (c) 1988-2017 $organization$
%#
%# This software is provided by the author and contributors ``as is'' 
%# and any express or implied warranties, including, but not limited to, 
%# the implied warranties of merchantability and fitness for a particular 
%# purpose are disclaimed. In no event shall the author or contributors 
%# be liable for any direct, indirect, incidental, special, exemplary, 
%# or consequential damages (including, but not limited to, procurement 
%# of substitute goods or services; loss of use, data, or profits; or 
%# business interruption) however caused and on any theory of liability, 
%# whether in contract, strict liability, or tort (including negligence 
%# or otherwise) arising in any way out of the use of this software, 
%# even if advised of the possibility of such damage.
%#
%#   File: QtCreator-executable-pri.t
%#
%# Author: $author$
%#   Date: 4/4/2017
%########################################################################
%with(%
%framework,%(%else-then(%framework%,%(Framework)%)%)%,%
%Framework,%(%else-then(%Framework%,%(%framework%)%)%)%,%
%FRAMEWORK,%(%else-then(%FRAMEWORK%,%(%toupper(%Framework%)%)%)%)%,%
%framework,%(%else-then(%_Framework%,%(%tolower(%Framework%)%)%)%)%,%
%target,%(%else-then(%target%,%(Target)%)%)%,%
%Target,%(%else-then(%Target%,%(%target%)%)%)%,%
%TARGET,%(%else-then(%TARGET%,%(%toupper(%Target%)%)%)%)%,%
%target,%(%else-then(%_Target%,%(%tolower(%Target%)%)%)%)%,%
%%(########################################################################
# Copyright (c) 1988-%year()% $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: %Target%.pri
#
# Author: $author$
#   Date: %date()%
########################################################################

%Target%_TARGET = %Framework%-%Target%

########################################################################
%Target%_INCLUDEPATH += \
$${%Framework%_INCLUDEPATH} \
$${crono_INCLUDEPATH} \
$${patrona_INCLUDEPATH} \
$${nadir_INCLUDEPATH} \

%Target%_DEFINES += \
$${framework_DEFINES} \
$${%Framework%_DEFINES} \

########################################################################
%Target%_HEADERS += \
$${%FRAMEWORK%_SRC}/%Framework%/console/Main_main.hpp \
$${%FRAMEWORK%_SRC}/%Framework%/base/Base.hpp \

%Target%_SOURCES += \
$${%FRAMEWORK%_SRC}/%Framework%/console/Main_main.cpp \
$${%FRAMEWORK%_SRC}/%Framework%/base/Base.cpp \

########################################################################
%Target%_LIBS += \
$${nadir_LIBS} \

)%)%
