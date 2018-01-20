########################################################################
# Copyright (c) 1988-2018 $organization$
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
#   File: Makefile
#
# Author: $author$
#   Date: 1/20/2018
#
# Thirdpary Makefile for patrona
########################################################################

########################################################################
#
# patrona defs
#
########################################################################
PATRONA_MAKEDIR=$(PWD)

PATRONA_THIRDPARTY = $(PATRONA_MAKEDIR)/..
#PATRONA_BUILD_HOME = $(PATRONA_THIRDPARTY)

ifndef PATRONA_UNAME
PATRONA_UNAME = $(shell uname)
endif

ifndef PATRONA_OS
ifneq ($(PATRONA_UNAME), Darwin)
PATRONA_OS = linux
else
PATRONA_OS = macosx
endif
endif

#
# patrona version
#
PATRONA_VERSION_MAJOR = 0
PATRONA_VERSION_MINOR = 0
PATRONA_VERSION_RELEASE = 0

PATRONA_VERSION_SEPARATOR = .
PATRONA_VERSION_MAJOR_SEPARATOR = $(PATRONA_VERSION_SEPARATOR)
PATRONA_VERSION_MINOR_SEPARATOR = $(PATRONA_VERSION_SEPARATOR)

PATRONA_VERSION_SHORT = $(PATRONA_VERSION_MAJOR)$(PATRONA_VERSION_MINOR)$(PATRONA_VERSION_RELEASE)
PATRONA_VERSION = $(PATRONA_VERSION_MAJOR)$(PATRONA_VERSION_MAJOR_SEPARATOR)$(PATRONA_VERSION_MINOR)$(PATRONA_VERSION_MINOR_SEPARATOR)$(PATRONA_VERSION_RELEASE)

#
# patrona name
#
PATRONA_NAME_SEPARATOR = -
PATRONA_NAME_BASE = patrona
PATRONA_NAME = $(PATRONA_NAME_BASE)$(PATRONA_NAME_SEPARATOR)$(PATRONA_VERSION)
PATRONA_INSTALL_NAME_SEPARATOR = -
PATRONA_INSTALL_NAME = $(PATRONA_NAME_BASE)$(PATRONA_INSTALL_NAME_SEPARATOR)$(PATRONA_VERSION)
PATRONA_DIR = $(PATRONA_NAME)

#
# patrona archive
#
PATRONA_ARCHIVED = tar
PATRONA_COMPRESSED = gz
PATRONA_ARCHIVE_SEPARATOR = .
PATRONA_ARCHIVED_SEPARATOR = $(PATRONA_ARCHIVE_SEPARATOR)
PATRONA_COMPRESSED_SEPARATOR = $(PATRONA_ARCHIVE_SEPARATOR)

PATRONA_EXTRACT_DIR = $(PATRONA_NAME)
PATRONA_TGZ_PREFIX = 
PATRONA_TGZ = $(PATRONA_NAME)$(PATRONA_TGZ_PREFIX)$(PATRONA_ARCHIVED_SEPARATOR)$(PATRONA_ARCHIVED)$(PATRONA_COMPRESSED_SEPARATOR)$(PATRONA_COMPRESSED)
PATRONA_PATCH_TGZ_PREFIX = $(PATRONA_NAME_SEPARATOR)patch
PATRONA_PATCH_TGZ = $(PATRONA_NAME)$(PATRONA_PATCH_TGZ_PREFIX)$(PATRONA_ARCHIVED_SEPARATOR)$(PATRONA_ARCHIVED)$(PATRONA_COMPRESSED_SEPARATOR)$(PATRONA_COMPRESSED)
PATRONA_DOCS_TGZ_PREFIX = $(PATRONA_NAME_SEPARATOR)docs
PATRONA_DOCS_TGZ = $(PATRONA_NAME)$(PATRONA_DOCS_TGZ_PREFIX)$(PATRONA_ARCHIVED_SEPARATOR)$(PATRONA_ARCHIVED)$(PATRONA_COMPRESSED_SEPARATOR)$(PATRONA_COMPRESSED)

#
# patrona extract
#
ifeq ($(PATRONA_ARCHIVED),tar)
ifeq ($(PATRONA_COMPRESSED),gz)
PATRONA_TAR_UNCOMPRESS = z
PATRONA_TAR_COMPRESS = z
else
ifeq ($(PATRONA_COMPRESSED),bz2)
PATRONA_TAR_UNCOMPRESS = j
PATRONA_TAR_COMPRESS = j
else
ifeq ($(PATRONA_COMPRESSED),xz)
PATRONA_TAR_UNCOMPRESS = J
PATRONA_TAR_COMPRESS = J
else
endif
endif
endif
PATRONA_LIST = tar -tv$(PATRONA_TAR_UNCOMPRESS)f
PATRONA_EXTRACT = tar -x$(PATRONA_TAR_UNCOMPRESS)f
PATRONA_ARCHIVE = tar -cv$(PATRONA_TAR_COMPRESS)f
else
ifeq ($(PATRONA_ARCHIVED),zip)
PATRONA_LIST = unzip -l
PATRONA_EXTRACT = unzip
PATRONA_ARCHIVE = zip
else
PATRONA_LIST = echo unable to list
PATRONA_EXTRACT = echo unable to extract
PATRONA_ARCHIVE = echo unable to archive
endif
endif

PATRONA_LIST_TGZ = $(PATRONA_LIST) $(PATRONA_TGZ)
PATRONA_EXTRACT_TGZ = $(PATRONA_EXTRACT) $(PATRONA_TGZ)
PATRONA_TOUCH_EXTRACT = touch $(PATRONA_DIR)
PATRONA_REMOVE_DIR = $(PATRONA_REMOVE) $(PATRONA_DIR)

PATRONA_LIST_PATCH = $(PATRONA_LIST)
PATRONA_EXTRACT_PATCH = $(PATRONA_EXTRACT)
PATRONA_LIST_PATCH_TGZ = $(PATRONA_LIST_PATCH) $(PATRONA_PATCH_TGZ)
PATRONA_EXTRACT_PATCH_TGZ = $(PATRONA_EXTRACT_PATCH) $(PATRONA_PATCH_TGZ)

PATRONA_LIST_DOCS = $(PATRONA_LIST)
PATRONA_EXTRACT_DOCS = $(PATRONA_EXTRACT)
PATRONA_LIST_DOCS_TGZ = $(PATRONA_LIST_DOCS) $(PATRONA_DOCS_TGZ)
PATRONA_EXTRACT_DOCS_TGZ = $(PATRONA_EXTRACT_DOCS) $(PATRONA_DOCS_TGZ) -C$(PATRONA_DOCS_PREFIX)

#
# patrona build
#
ifndef PATRONA_BUILD_HOME
PATRONA_BUILD = $(HOME)/build
else
PATRONA_BUILD = $(PATRONA_BUILD_HOME)/build
endif
PATRONA_PREFIX = $(PATRONA_BUILD)/$(PATRONA_INSTALL_NAME)
PATRONA_EXEC_PREFIX = $(PATRONA_PREFIX)
PATRONA_CONF_PREFIX = $(PATRONA_PREFIX)
PATRONA_DOCS_PREFIX = $(PATRONA_PREFIX)
PATRONA_LINK_NAME = $(PATRONA_BUILD)/$(PATRONA_NAME_BASE)

PATRONA_MKDIR = mkdir -p
PATRONA_REMOVE = rm -r -f

PATRONA_MAKE_DIR = $(PATRONA_DIR)
PATRONA_MAKE_PUSHD = pushd $(PATRONA_MAKE_DIR)
PATRONA_MAKE = make

#
# patrona configure
#
ifneq ($(PATRONA_UNAME), Darwin)
PATRONA_CONFIGURE_UNAME = 
else
PATRONA_CONFIGURE_UNAME = 
endif
PATRONA_CONFIGURE_CONFIGURE = ./configure
PATRONA_CONFIGURE_HELP = $(PATRONA_CONFIGURE_CONFIGURE) --help
PATRONA_CONFIGURE_PUSHD = pushd $(PATRONA_MAKE_DIR)
PATRONA_CONFIGURE = $(PATRONA_CONFIGURE_CONFIGURE) \
$(PATRONA_CONFIGURE_UNAME) --prefix=$(PATRONA_PREFIX) --exec_prefix=$(PATRONA_EXEC_PREFIX)

#
# patrona help
#
PATRONA_HELP = $(PATRONA_CONFIGURE_HELP)

########################################################################
#
# rules
#
########################################################################

all: build

package: archive unextract

again: unextract build

test: test-patrona

install-links: install-patrona-links

install-docs: install-patrona-docs

install-prefix: install-patrona-prefix

install: install-patrona

build: build-patrona

clean: clean-patrona

configed: configed-$(PATRONA_DIR)

config: config-$(PATRONA_DIR)

help: help-patrona

list-docs: list-patrona-docs

list-patch: list-patrona-patch

extract-patch: extract-patrona-patch

list: list-patrona

extract: extract-patrona

unextract: unextract-patrona

archive: archive-patrona

linked: patrona-linked

prefixed: patrona-prefixed

archived: patrona-archived

extracted: patrona-extracted

########################################################################
#
# patrona rules
#
########################################################################

#
# Help patrona
#
help-patrona: $(PATRONA_DIR)
	@($(PATRONA_CONFIGURE_PUSHD);\
	  (($(PATRONA_HELP)) || (exit 1));\
	  popd)

#
# Install patrona
#
install-patrona: configed-$(PATRONA_DIR)
	@(echo Installing $(PATRONA_DIR)...;\
	  $(PATRONA_MAKE_PUSHD);\
	  (($(PATRONA_MAKE) install) || (exit 1)) && \
	  ((touch $(PATRONA_MAKEDIR)/configed-$(PATRONA_DIR)) || (exit 1));\
	  popd)
	  
#
# Build patrona
#
build-patrona: configed-$(PATRONA_DIR)
	@(echo Building $(PATRONA_DIR)...;\
	  $(PATRONA_MAKE_PUSHD);\
	  (($(PATRONA_MAKE)) || (exit 1)) && \
	  ((touch $(PATRONA_MAKEDIR)/configed-$(PATRONA_DIR)) || (exit 1));\
	  popd)
	  
#
# Clean patrona
#
clean-patrona: configed-$(PATRONA_DIR)
	@(echo Cleaning $(PATRONA_DIR)...;\
	  $(PATRONA_MAKE_PUSHD);\
	  (($(PATRONA_MAKE) clean) || (exit 1)) && \
	  ((touch $(PATRONA_MAKEDIR)/configed-$(PATRONA_DIR)) || (exit 1));\
	  popd)
	  
#
# Test patrona
#
test-patrona: configed-$(PATRONA_DIR)
	@(echo Building test $(PATRONA_DIR)...;\
	  $(PATRONA_MAKE_PUSHD);\
	  (($(PATRONA_MAKE) test) || (exit 1)) && \
	  ((touch $(PATRONA_MAKEDIR)/configed-$(PATRONA_DIR)) || (exit 1));\
	  popd)
	  
#
# Config patrona
#
config-$(PATRONA_DIR): unconfig-$(PATRONA_DIR) configed-$(PATRONA_DIR)

unconfig-$(PATRONA_DIR):
	@(rm -f configed-$(PATRONA_DIR))

configed-$(PATRONA_DIR): $(PATRONA_DIR)
	@(echo Configing $(PATRONA_DIR)...;\
	  $(PATRONA_CONFIGURE_PUSHD);\
	  (($(PATRONA_CONFIGURE)) || (exit 1)) && \
	  ((touch $(PATRONA_DIR)) || (exit 1)) && \
	  ((touch $(PATRONA_MAKEDIR)/configed-$(PATRONA_DIR)) || (exit 1));\
	  popd)

########################################################################
# docs
########################################################################

#
# List patrona Docs
#
list-patrona-docs: $(PATRONA_DOCS_TGZ)
	@(echo Listing $(PATRONA_DOCS_TGZ)...;\
	  (($(PATRONA_LIST_DOCS_TGZ)) || (exit 1)))

#
# Install patrona Docs
#
install-patrona-docs: $(PATRONA_DOCS_PREFIX)
	@(echo Extracting $(PATRONA_DOCS_TGZ)...;\
	  (($(PATRONA_EXTRACT_DOCS_TGZ)) || (exit 1)))

########################################################################
# patch
########################################################################

#
# List patrona Patch
#
list-patrona-patch: $(PATRONA_PATCH_TGZ)
	@(echo Listing $(PATRONA_PATCH_TGZ)...;\
	  (($(PATRONA_LIST_PATCH_TGZ)) || (exit 1)))

#
# Extract patrona patch
#
extract-patrona-patch: $(PATRONA_DIR)
	@(echo Extracting $(PATRONA_PATCH_TGZ)...;\
	  (($(PATRONA_EXTRACT_PATCH_TGZ)) || (exit 1)))

########################################################################
# archive
########################################################################

#
# List patrona
#
list-patrona: 
	@(echo Listing $(PATRONA_TGZ)...;\
	  (($(PATRONA_LIST_TGZ)) || (exit 1)))

#
# patrona extracted
#
patrona-extracted: 
	@(echo $(PATRONA_EXTRACT) $(PATRONA_TGZ))

#
# Extract patrona
#
extract-patrona: unextract-patrona $(PATRONA_DIR)

unextract-patrona: unconfig-$(PATRONA_DIR)
	@(echo Removing $(PATRONA_DIR)...;\
	  (($(PATRONA_REMOVE_DIR)) || (exit 1)))

$(PATRONA_DIR): $(PATRONA_TGZ)
	@(echo Extracting $(PATRONA_TGZ)...;\
	  (($(PATRONA_EXTRACT_TGZ)) || (exit 1)) && \
	  (($(PATRONA_TOUCH_EXTRACT)) || (exit 1)))
	  
#
# patrona archived
#
patrona-archived: 
	@(echo $(PATRONA_TGZ))
	  
#
# Archive patrona
#
archive-patrona: 
	@(echo Archiving $(PATRONA_DIR) to $(PATRONA_TGZ)...;\
	  (($(PATRONA_ARCHIVE) $(PATRONA_TGZ) $(PATRONA_DIR)) || (exit 1)))

########################################################################
# links
########################################################################

#
# patrona linked
#
patrona-linked: 
	@echo link is $(PATRONA_LINK_NAME) "->" $(PATRONA_PREFIX)
	  
#
# Install patrona links
#
install-patrona-links: 
	@((echo removing $(PATRONA_LINK_NAME)) && \
	  ((rm -f $(PATRONA_LINK_NAME)) || (exit 1)) && \
	  (echo Linking $(PATRONA_LINK_NAME) "->" $(PATRONA_PREFIX)) && \
	  ((ln -s $(PATRONA_PREFIX) $(PATRONA_LINK_NAME)) || (exit 1)))
	  
########################################################################
# prefix
########################################################################

#
# patrona prefixed
#
patrona-prefixed: 
	@((echo prefix is $(PATRONA_PREFIX)) && \
	  (echo exec prefix is $(PATRONA_EXEC_PREFIX)) && \
	  (echo conf prefix is $(PATRONA_CONF_PREFIX)) && \
	  (echo docs prefix is $(PATRONA_DOCS_PREFIX)))
	  
#
# Install patrona prefix
#
install-patrona-prefix: 
	@((echo makeing $(PATRONA_PREFIX)) && \
	  ((mkdir -p $(PATRONA_PREFIX)) || (exit 1)) && \
	  (echo makeing $(PATRONA_EXEC_PREFIX)) && \
	  ((mkdir -p $(PATRONA_EXEC_PREFIX)) || (exit 1)))
	  
$(PATRONA_PREFIX):
	@(echo Makeing Directory $(PATRONA_PREFIX)...;\
	  (($(PATRONA_MKDIR) $(PATRONA_PREFIX)) || (exit 1)))

$(PATRONA_EXEC_PREFIX):
	@(echo Makeing Directory $(PATRONA_EXEC_PREFIX)...;\
	  (($(PATRONA_MKDIR) $(PATRONA_EXEC_PREFIX)) || (exit 1)))

$(PATRONA_CONF_PREFIX):
	@(echo Makeing Directory $(PATRONA_CONF_PREFIX)...;\
	  (($(PATRONA_MKDIR) $(PATRONA_CONF_PREFIX)) || (exit 1)))

$(PATRONA_DOCS_PREFIX):
	@(echo Makeing Directory $(PATRONA_DOCS_PREFIX)...;\
	  (($(PATRONA_MKDIR) $(PATRONA_DOCS_PREFIX)) || (exit 1)))




        

