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
%#   File: Created.t
%#
%# Author: $author$
%#   Date: 3/28/2017
%########################################################################
%with(%
%attached,%(%else-then(%attached%,%(Attached)%)%)%,%
%Attached,%(%else-then(%Attached%,%(%attached%)%)%)%,%
%ATTACHED,%(%else-then(%ATTACHED%,%(%toupper(%Attached%)%)%)%)%,%
%attached,%(%else-then(%_Attached%,%(%tolower(%Attached%)%)%)%)%,%
%to,%(%else-then(%to%,%(To)%)%)%,%
%To,%(%else-then(%To%,%(%to%)%)%)%,%
%TO,%(%else-then(%TO%,%(%toupper(%To%)%)%)%)%,%
%to,%(%else-then(%_To%,%(%tolower(%To%)%)%)%)%,%
%type,%(%else-then(%type%,%(Type)%)%)%,%
%Type,%(%else-then(%Type%,%(%type%)%)%)%,%
%TYPE,%(%else-then(%TYPE%,%(%toupper(%Type%)%)%)%)%,%
%type,%(%else-then(%_Type%,%(%tolower(%Type%)%)%)%)%,%
%param,%(%else-then(%param%,%(Param)%)%)%,%
%Param,%(%else-then(%Param%,%(%param%)%)%)%,%
%PARAM,%(%else-then(%PARAM%,%(%toupper(%Param%)%)%)%)%,%
%param,%(%else-then(%_Param%,%(%tolower(%Param%)%)%)%)%,%
%class,%(%else-then(%class%,%(Class)%)%)%,%
%Class,%(%else-then(%Class%,%(%class%)%)%)%,%
%CLASS,%(%else-then(%CLASS%,%(%toupper(%Class%)%)%)%)%,%
%class,%(%else-then(%_Class%,%(%tolower(%Class%)%)%)%)%,%
%%(
typedef %Attached% %Class%AttachedTo;

typedef patrona::CreatorT<ImplementBase> %Class%TCreator;
typedef patrona::AttacherT
<%Class%AttachedTo, int, 0, %Class%TCreator> %Class%TAttacher;
typedef patrona::AttachedT
<%Class%AttachedTo, int, 0, %Class%TAttacher, Base> %Class%TAttached;
typedef patrona::CreatedT
<%Class%AttachedTo, int, 0, %Class%TAttacher, %Class%TAttached> %Class%TCreated;

typedef %Class%TAttacher %Class%TImplements;
typedef %Class%TCreated %Class%TExtends;
///////////////////////////////////////////////////////////////////////
///  Class: %Class%T
///////////////////////////////////////////////////////////////////////
template
<class TImplements = %Class%TImplements, class TExtends = %Class%TExtends>
class _EXPORT_CLASS %Class%T: virtual public TImplements,public TExtends {
public:
    typedef TImplements Implements;
    typedef TExtends Extends;

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    %Class%T(%Attached% attachedTo = 0, bool IsCreated = false)
    : Extends(attachedTo, IsCreated) {
    }
    %Class%T(const %Class%T& copy): Extends(copy) {
    }
    virtual ~%Class%T() {
        if (!(this->Destroyed())) {
            patrona::CreateException e(patrona::DestroyFailed);
            CRONO_LOG_ERROR("...throwing patrona::CreateException e(patrona::DestroyFailed)...");
            throw (e);
        }
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual bool Create(%Type% %Param%) {
        %Attached% %To% = 0;

        if ((%To% = CreateAttached(%Param%))) {
            this->SetIsCreated();
            return true;
        }
        return false;
    }
    virtual %Attached% CreateAttached(%Type% %Param%) {
        %Attached% %To% = 0;

        if ((%To% = CreateDetached(%Param%))) {
            this->Attach(%To%);
            return %To%;
        }
        return 0;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
    virtual %Attached% CreateDetached(%Type% %Param%) const {
        %Attached% %To% = 0;

        CRONO_LOG_DEBUG("...");
        if ((true)) {
            return %To%;
        } else {
            CRONO_LOG_ERROR("...failed on ");
        }
        return 0;
    }
    virtual bool DestroyDetached(%Attached% %To%) const {
        if ((%To%)) {
            bool success = true;

            CRONO_LOG_DEBUG("...");
            if ((true)) {
                CRONO_LOG_DEBUG("...failed on ");
                success = false;
            }
            return success;
        }
        return false;
    }

    ///////////////////////////////////////////////////////////////////////
    ///////////////////////////////////////////////////////////////////////
};
typedef %Class%T<> %Class%;
)%)%