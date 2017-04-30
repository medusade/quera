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
%#   File: QtCreator-framework-pri.t
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
%os,%(%else-then(%os%,%(Os)%)%)%,%
%Os,%(%else-then(%Os%,%(%os%)%)%)%,%
%OS,%(%else-then(%OS%,%(%toupper(%Os%)%)%)%)%,%
%os,%(%else-then(%_Os%,%(%tolower(%Os%)%)%)%)%,%
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
#   File: %Framework%.pri
#
# Author: $author$
#   Date: %date()%
########################################################################

########################################################################
# %Framework%
%FRAMEWORK%_PKG = $${FRAMEWORK_PKG}/../%Framework%
%FRAMEWORK%_PRJ = $${FRAMEWORK_PRO_DIR}$${%FRAMEWORK%_PKG}
%FRAMEWORK%_SRC = $${%FRAMEWORK%_PRJ}/src
%FRAMEWORK%_BLD = ../$${%FRAMEWORK%_PKG}/build/$${FRAMEWORK_OS}/QtCreator/$${FRAMEWORK_CONFIG}
%FRAMEWORK%_LIB = $${%FRAMEWORK%_BLD}/lib

%Framework%_INCLUDEPATH += \
$${%FRAMEWORK%_SRC} \
$${crono_INCLUDEPATH} \
$${nadir_INCLUDEPATH} \
$${patrona_INCLUDEPATH} \

%Framework%_DEFINES += \

%Framework%_LIBS += \
-L$${%FRAMEWORK%_LIB}/lib%Framework% \
-l%Framework% \
)%)%
