########################################################################
# Copyright (c) 1988-2017 $organization$
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
#   File: framework.pri
#
# Author: $author$
#   Date: 3/12/2017
########################################################################
FRAMEWORK_PKG = ../../../../..
FRAMEWORK_BLD = ../..

FRAMEWORK_PRJ = $${FRAMEWORK_PRO_DIR}$${FRAMEWORK_PKG}
FRAMEWORK_BIN = $${FRAMEWORK_BLD}/bin
FRAMEWORK_LIB = $${FRAMEWORK_BLD}/lib
FRAMEWORK_SRC = $${FRAMEWORK_PRJ}/src

FRAMEWORK_THIRDPARTY = $${FRAMEWORK_PRO_DIR}$${FRAMEWORK_PKG}/thirdparty
FRAMEWORK_THIRDPARTY_BLD = $${FRAMEWORK_PRO_DIR}$${FRAMEWORK_PKG}/../thirdparty

########################################################################
CONFIG(debug, debug|release) {
FRAMEWORK_CONFIG = Debug
framework_DEFINES += DEBUG_BUILD
} else {
FRAMEWORK_CONFIG = Release
framework_DEFINES += RELEASE_BUILD
}
framework_DEFINES += BUILD_CONFIG=$${FRAMEWORK_CONFIG}
